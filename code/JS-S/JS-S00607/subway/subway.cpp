#include<bits/stdc++.h>
#define int long long
using namespace std;
void fre(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}

int c,r,m,d,q;
int w[100086],a[1000][1000],t[1000][1000];
int ans=0,k[1000000],x,y,ans=0;

signed main(){
    fre();
    cin>>c>>r>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x) int k;k++;
                if(a[i][j]==y) int k++;
            }
        }
        if(k==2) cout<<t[1][1]*4;
    }
}
