#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10005],dp[10005][10005],max01=-1;
int main()
{

      freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[1][i]=a[i];
    }

    for(int i=2;i<=m;i++){
         max01=-1;
        for(int j=1;j<=n;j++){

            for(int z=1;z<=n;z++){
                    if(i==2&&j==z)
                    continue;
                max01=max(max01,dp[i-1][j]&dp[1][z]);

            }

            dp[i][j]=max01;
        }
    }
    max01=-1;

for(int i=1;i<=n;i++){
  max01=max(dp[m][i],max01);
}

cout<<max01<<endl;
    return 0;
}
