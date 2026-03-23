#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function to check if a number is invalid (sequences repeated at least twice)
bool isInvalid(long long n){
    string s = to_string(n);
    int len = s.size();

    //no leading zeros allowed
    if (s[0] == '0') return false;

    //try every possible sequence length that divides the total length
    //sequence must repeat at least twice, so max length is len/2
    for (int seqLen=1; seqLen<=len/2; seqLen++){
        //sequence length must divide total length evenly
        if (len%seqLen != 0) continue;

        //extract the candidate sequence (first seqLen digits)
        string seq = s.substr(0, seqLen);

        //rebuild the full number by repeating the sequence
        string repeat = "";
        for (int i=0; i<len/seqLen; i++)
            repeat += seq;

        //if it matches, the number is invalid
        if (repeat == s) return true;
    }

    return false;
}

int main(){
    ifstream file("input.txt");
    string line;
    getline(file, line);

    //using long long instead of int because range bounds can be very large
    long long sum = 0;

    //split by commas to get each range
    int start = 0;
    for (int i=0; i<=line.size(); i++){
        
        //when we hit a comma or end of line, we have a full range
        if (i==line.size() || line[i]==','){
            string range = line.substr(start, i-start);
            start = i + 1;

            //split the range by '-' to get A and B
            int dash = range.find('-');
            long long A = stoll(range.substr(0, dash));
            long long B = stoll(range.substr(dash+1));

            //check every number in the range
            for (long long n=A; n<=B; n++){
                if (isInvalid(n)) sum += n;
            }
        }
    }

    cout << "Solution part2: " << sum << endl;

    return 0;
}