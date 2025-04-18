#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
#define int long long 

signed main()
{
    int n;cin>>n;
    vector<int>v={1,2,3,4,5,6};
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<=n;i++)
    {
        for(auto it:v)
        {
            if(i-it>=0)
            {
                dp[i]+=dp[i-it];
            }
            dp[i]%=MOD;
        }
    }
    cout<<dp[n]<<endl;
}