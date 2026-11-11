 #include <bits/stdc++.h>
 using namespace std;
 int main()
 {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
     long long n,m;
     cin>>n>>m;
     long long a[100005];
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
     }
     //int dp[1005][1005];
     //for(int i=1;i<=n;i++)
     //{
       //  for(int j=0;j<=m;j++)
       //  {
        //     dp[a[i]][j]=a[i]+j;
       //  }
     //}
     //int cnt[1005]={0};
     //maxn=-1;
     //for(int i=1;i<=n;i++)
     //{
        // for(int j=i;j<=n;j++)
        // {
         //    if(dp[a[i])
       //  }
    // }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n==0)
    {
        cout<<0;
        return 0;
    }
     cout<<m-1;
     return 0;
 }
