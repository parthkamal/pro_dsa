#include <bits/stdc++.h>

using namespace std;


// find the prefix common arrays of two arrays 
// problem -> https://leetcode.com/contest/biweekly-contest-103/problems/find-the-prefix-common-array-of-two-arrays/
// submission -> https://leetcode.com/submissions/detail/1108834233/

/* logic -> 

  har ek iteration me hame no of common characters between both the arrays nikalne hai, aur ek elements me kabhi elements repeat nhi karenge. 
  kyuki array ek permutation diya hua hai. 
  to jab bhi common characters ayenge wo do arrays ke bich me hi hoge. 

  iss problem ko ham set ke through kar skte hai aram se. 
  during each iteration we can find the number of common characters till now with set size. 
  aur phir usi ko ans me push_back karate jayenge. 
  
*/

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    unordered_set<int> present; 

    int size = A.size();

    vector<int> ans;

    for(int i=0;i<size;i++){
        present.insert(A[i]);
        present.insert(B[i]);
        int common = (i+1)*2 - present.size();
        ans.push_back(common);
    }      

    return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; 
    cin>>n; 
    vector<int> A(n), B(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    } 

    for(int i=0;i<n;i++){
        cin>>B[i];
    }

    vector<int> ans =findThePrefixCommonArray(A,B);


    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}
