#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a,t;
int w[500010],k[510];
int mp[10510][10510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            if(i==j)  mp[i][j]=0;
            else mp[i][j]=1e9+5;
        }
    }
    int l,r;
    for(int i=1;i<=m;i++)  cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            mp[m+i][a]=t;
            mp[a][m+i]=t;
        }
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            for(int p=1;p<=n+m;p++){
                if(mp[j][p]>mp[j][i]+mp[i][p])  mp[j][p]=mp[j][i]+mp[i][p];
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        cout<<w[l]+w[r]+mp[l][r]<<endl;
    }
    return 0;
}
