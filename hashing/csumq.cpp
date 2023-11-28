#include <bits/stdc++.h>

using namespace std;

// csumq -> https://www.spoj.com/problems/CSUMQ/
// submission -> https://www.spoj.com/status/CSUMQ,parthkamal/


/* logic -> 
sum(0,l -1) + sum(l,r) = sum(0,r)
sum(l,r) = sum(0,r) - sum(0, l-1)

ek hashmap me sum store karlo , then , return each query upar wale logic se
*/



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n,q; 
    cin>>n>>q; 

    vector<int> nums(n); 

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> pref(n+1);

    pref[0] = 0; 
    for(int i=1;i<=n;i++){
        pref[i] = nums[i-1]+ pref[i-1];
    }

    while(q--){
        int l,r ;
        cin>>l>> r; 
        int ans = pref[r+1]- pref[l];
        cout<<ans<<endl;
    }
    return 0;
}
