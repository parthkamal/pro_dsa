#include <bits/stdc++.h>

using namespace std;

// LONGEST CONSECUTIVE SEQUENCE
// problem -> https://leetcode.com/problems/longest-consecutive-sequence/
// submission -> https://leetcode.com/problems/longest-consecutive-sequence/submissions/1108758399/ 


/* logic -> 
	since we have to find a sequence, to matlab frequency doesn't matters
	to phir hmlog kya karenge ki ek present ka set banalo.
	aur phir dubara iteration me find karo ki curr index starting index hai kisi sequence ka ya nhi. 
	then agar hai, to while loop chala ke uss sequence ki length nikal lo. 
	and then udpate the max_size in each iteration. 
	aur check me daalte rho. jo starting index complete ho jaaye. taaki wo loop repeat na ho.
*/
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> present; 
    unordered_set<int> check; 

    int size = nums.size();

    for(int i=0;i<size;i++){
        int curr = nums[i];
        present.insert(curr);
    }

    int max_size= 0;

    for(int i=0;i<size;i++){
        int curr = nums[i];
        if(present.find(curr-1) == present.end()){
            if(check.find(curr)== check.end()){
                int curr_size = 0;
                while(present.find(curr)!=present.end()){
                    check.insert(curr);
                    curr_size++; 
                    curr++;
                }

                max_size = max(max_size,curr_size);
            }
        }
    }

    return max_size;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int size; 
    cin>>size;

    vector<int> nums(size);

    for(int i=0;i<size;i++){
        cin>>nums[i];
    }

    int ans = longestConsecutive(nums);
    cout<<ans<<endl;

    return 0;
}
