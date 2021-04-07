#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> a = {1, 5, 11, 5};

bool canPartition(vector<int>& nums) {
    if(nums.size()<2)
        return false;
    int sum = 0;
    int maxnum = 0;
    for (int i = 0;  i < nums.size();i++){
        sum += nums[i];
        maxnum = max(maxnum, nums[i]);
    }
    if(sum%2==1)
        return false;
    int target = sum / 2;//目标
    if(maxnum>target)
        return false;
    bool dp[100][100]={false};
    for (int i = 0; i < nums.size();i++){
        dp[i][0] = false;
    }
    dp[0][nums[0]] = true;

    for (int i = 1; i < nums.size();i++){
        for (int j = 1; j <= target;j++){
            if(j>nums[i]){
                //?疑惑小林
            }
            else{
                dp[i][j] = dp[i - 1][j - nums[i]];
            }
        }
    }
}

int main(){
    cout << canPartition(a);
    system("pause");
    return 0;
}