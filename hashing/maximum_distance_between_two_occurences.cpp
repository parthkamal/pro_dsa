#include <bits/stdc++.h>

using namespace std;

// maximum sum between two occurence of a element in an array
// problem -> https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/
// submission -> https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/* logic -> 
ek first occurence ka hashmap rakho aur ek last ka ,
then find the max distance by taking each distinct element.
*/

int maxDistance(int arr[], int n)
{
    int distance = 0; 
    map<int,int> first_occ, last_occ; 

    for(int i=0;i<n;i++){
        int curr = arr[i];
        if(first_occ.find(curr) == first_occ.end()){
            first_occ[curr]= i;
        }
        last_occ[curr] = i; 
    }

    for(auto it: first_occ){
        int key = it.first;
        distance = max(distance, last_occ[key] - first_occ[key]);
    }

    return distance;
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; 
    cin>>n; 

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = maxDistance(arr,n); 
    cout<<ans<<endl;
    return 0;
}
