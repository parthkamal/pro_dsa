#include <bits/stdc++.h>

using namespace std;


// count number of pairs with absolute difference k
// problem -> https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// submission -> https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/submissions/1108776732/

/* logic -> 

  let a and b are the two numbers
  and | a- b | = k , to phir a - b = k || a - b = -k
  b = a+k, b = a-k;

  to hame kya karna hai ek frequence map bnana hai. 
  to jaise maanlo , during iteration, ek curr is at position i, 
  then the numbers of such pairs whose j value is curr_idx , will be map(curr-k) + map(curr+k)
  to aise hi frequency maintain karte hu. saare count add karte jayenge, and then we will get the answer

*/
int countKDifference(vector<int>& nums, int k){

    unordered_map<int,int> freq; 
    int size = nums.size();

    int ans = 0;

    for(int i=0;i<size;i++){
        int curr = nums[i];
        ans += (freq[curr-k] +  freq[curr+k]);
        freq[curr]++; 
    }

    return ans;
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int size, k; 
    cin>>size>>k; 

    vector<int> nums(size); 

    for(int i=0;i<size;i++){
        cin>>nums[i];
    }

    int ans = countKDifference(nums,k); 
    cout<<ans<<endl;

    return 0;
}
