#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000009],dp[5009][5009],cnt=0,a[5009][5009];
bool v[5009][5009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(a[j]-a[i])<=d) v[i][j]=v[j][i]=1;
        }
    }for(int i=1;i<=n-2;i++){
        for(int j=i+2;j<=n;j++){
            if(v[i][j]&&!v[i+1][j]&&!v[i][i+1]) cnt++;
        }
    }printf("%d",cnt);
}
