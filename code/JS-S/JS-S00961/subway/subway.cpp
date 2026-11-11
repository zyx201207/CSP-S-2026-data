#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    int n;
    int m;
    int d;
    int q;
    cin>>c;
    cin>>n;
    cin>>m;
    cin>>d;
    cin>>q;
    int dp[m+5];
    dp[1]=99999999;
    int x[q+5];
    int y[q+5];
    int a[505][505];
    int t[505][505];
    int k;
    int w[m+5];
    int l[m+5];
    int s[m+5];
    int ans=0;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>K;
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i];
        cin>>y[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=k;l++){
                if(a[j][l]==i){
                    dp[i]=min(dp[i],t[j][l]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=x[i];j<=y[i];j++){
            ans=dp[i]+ans;
        }
        cout<<w[x[i]]+w[y[i]]+ans;
        cout<<endl;
    }
}
