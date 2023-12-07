#include <bits/stdc++.h>

using namespace std;


// subarrays with sum k
// problem -> https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article/
// submission -> https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/* logic -> 

  subarry sum manlo k hai. 
  sum(0,l-1) = sum(0,r) -k/ hoga.. 
  aur mujhe number of subarray find karna hai na. 
  to me kya kar skta hu , ki ek freq array bana skta hu, jisme curr_sum ki frequence update karta rhunga. 
  aur phir har iteration me , me curr_sum - k ka count find karunga. which means, aise saare arrays jo ki curr_idx pr end kar rhe hai unsabhi aubarrays ka count
  whi add karte jayenge aur return karadenge count 

  initially curr_sum ko bhi plus karenge because, empty subarray bhi count hoga.
*/

int findSubArraySum(int nums[], int size, int k)
{
    unordered_map<int,int> freq;
    int curr_sum = 0; 
    freq[curr_sum]++; 

    int ans = 0; 

    for(int i=0;i<size;i++){
        int curr = nums[i];
        curr_sum += curr; 
        ans += freq[curr_sum - k];
        freq[curr_sum ]++;
    }    

    return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int size,k;
    cin>>size>>k; 

    int nums[size];

    for(int i=0;i<size;i++){
        cin>>nums[i];
    }

    int ans = findSubArraySum(nums,size,k);
    cout<<ans<<endl;
    return 0; }
