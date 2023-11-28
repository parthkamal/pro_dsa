#include <bits/stdc++.h>

using namespace std;

// two sum -> https://leetcode.com/problems/two-sum/
// submission -> https://leetcode.com/problems/two-sum/submissions/1108053061/

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();
    map<int, int> pos;

    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        int x = nums[i];
        int y = target - x;

        if (pos.find(y) != pos.end())
        {
            ans.push_back(pos[y]);
            ans.push_back(i);
            break;
        }

        pos[x] = i;
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int size, target;
    cin >> size >> target;

    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = twoSum(nums, target);
    for(int x : ans){
        cout<<x<<" ";
    }

    cout<<endl;

    return 0;
}
