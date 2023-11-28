#include <bits/stdc++.h>

using namespace std;

// FIND COMMON CHARACTERS
// problem -> https://leetcode.com/problems/find-common-characters/
// submission -> https://leetcode.com/problems/find-common-characters/submissions/1108106001/

/* logic ->
ek hashmap common characters ki frequence store karega.
and dusra hashmap. ( curr ) jo ki curr string ki frequency store karega.
// aur phir har ek iteration me, hm common wale hashmap ko update karenge. my taking the min of common and curr hashmap
*/

vector<string> commonChars(vector<string> &words)
{
    map<char, int> freq;
    for (int j = 0; j < words.size(); j++)
    {
        string word = words[j];
        if (j == 0)
        {
            map<char, int> curr_freq;
            for (int i = 0; i < word.size(); i++)
            {
                char curr = word[i];
                curr_freq[curr]++;
            }

            for (auto it : curr_freq)
            {
                char key = it.first;
                int val = it.second;

                freq[key] = max(freq[key], curr_freq[key]);
            }
        }
        else
        {
            map<char, int> curr_freq;
            for (int i = 0; i < word.size(); i++)
            {
                char curr = word[i];
                curr_freq[curr]++;
            }

            for (auto it : freq)
            {
                char key = it.first;
                int val = it.second;

                freq[key] = min(freq[key], curr_freq[key]);
            }
        }
    }

    vector<string> ans;

    for (auto it : freq)
    {
        char curr = it.first;
        int curr_freq = it.second;
        for (int i = 0; i < curr_freq; i++)
        {
            ans.push_back(string(1,curr));
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

    int size_words;
    cin >> size_words;

    vector<string> words(size_words);
    for (int i = 0; i < size_words; i++)
    {
        cin >> words[i];
    }

    vector<string> ans = commonChars(words);

    for (string word : ans)
    {
        cout << word << " ";
    }

    cout << endl;
    return 0;
}
