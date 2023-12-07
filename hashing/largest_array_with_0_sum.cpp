#include <bits/stdc++.h>

using namespace std;


// largest subarray with 0 sum
// problem -> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// submission -> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article 

/* logic -> 

  agar subarray sum 0 search kar rhe hai , to sum(0,l-1) = sum(0,r) hoga. 
  to basically me curr_sum maintain karna hai, aur check karna hai ki wo sum phle bhi kabhi aaya, tha
  aur kis position par aaya tha ye hm ek map me store karlenge. 
  since length ko maximise karna hai to. hmlog keval phli bar hi ek curr_sum ki value ko map me dalenge. 

*/

int maxLen(vector<int>&nums, int size){
    unordered_map<int,int> pos; 

    int max_len =0;
    int curr_sum =0 ; 

    pos[curr_sum] = 0;

    for(int i=0;i<size;i++){
        int curr = nums[i];
        curr_sum += curr;
        if(pos.find(curr_sum) == pos.end()){
            pos[curr_sum] = i+1; 
        }else {
            int curr_len = i - pos[curr_sum] +1 ;
            max_len = max(curr_len,max_len);
        }
    }

    return max_len;
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

    int ans = maxLen(nums,size);
    cout<<ans<<endl;

    return 0;
}
