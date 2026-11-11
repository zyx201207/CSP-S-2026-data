#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int MAXN=2e5+99;
int n,m;
int a[10];
int dp[10];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<pow(2,n);i++)
    {
        int ans2=0;
        int tmp=i;
        vector<int>vec;
        while (tmp!=0){
            vec.push_back(tmp%2);
            tmp/=2;
        }
        int k=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==0){
                continue;
            }
            else{
                k++;
                if(ans2==0){
                    ans2=a[i+1];
                }
                else{
                    ans2&=a[i+1];
                }
                
            }
        }
        if(k!=m)
        {
            continue;
        }
        ans=max(ans,ans2);
        
    }
    cout<<ans;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=m;j>=1;j--)
    //     {
    //         if(dp[j-1]==0){
    //             dp[j-1]=a[i];
    //         }
    //         else{
    //             dp[j]=max(dp[j],dp[j-1]&a[i]);
    //             dp[j-1]=0;
    //         }
            
    //     }
    //  }
    // for(int i=1;i<=m;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    return 0;
}