#include <bits/stdc++.h>

using namespace std;

// FIRST UNIQUE CHARACTER IN A STRING
// problem -> https://leetcode.com/problems/first-unique-character-in-a-string/description/
// submission -> https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1108090336/

/* logic ->
 saare characters ki frequency store karlo, phir traverse krlo, ki sbse phle kiski freq 1 mile, whi se break kara do
*/

int firstUniqChar(string s)
{
    int size = s.size();

    int ans = -1; 
    map<char,int> freq; 

    for(int i=0;i<size;i++){
        char curr = s[i];
        freq[curr] ++;
    }

    for(int i=0;i<size;i++){
        char curr = s[i];
        if(freq[curr] == 1){
            ans = i ; 
            break;
        }
    }

    return ans; 
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s; 
    cin>>s; 
    int ans = firstUniqChar(s); 
    cout<<ans<<endl; 
    return 0;
}
