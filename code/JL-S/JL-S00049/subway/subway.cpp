#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[505];
vector<int>a[505];
vector<int>t[505];
vector<int>k[500005];
vector<int>cnt[500005];
int num[505][505];
int w[500005];
signed main(){
     freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(num,0x3f,sizeof(num));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
        a[i].resize(f[i]+1);
        t[i].resize(f[i]+1);
        for(int j=1;j<=f[i];j++){
            cin>>a[i][j]>>t[i][j];
            k[a[i][j]].push_back(i);
            cnt[a[i][j]].push_back(t[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        num[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<k[i].size();j++){
            for(int z=j+1;z<k[i].size();z++){
                num[k[i][j]][k[i][z]]=min(num[k[i][j]][k[i][z]],cnt[i][j]+cnt[i][z]);
                num[k[i][z]][k[i][j]]=min(num[k[i][z]][k[i][j]],cnt[i][j]+cnt[i][z]);
            }
        }
    }
    //cout<<"dick";
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                num[i][j]=min(num[i][j],num[i][k]+num[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=LONG_LONG_MAX;
        for(int j=0;j<k[x].size();j++){
            for(int z=0;z<k[y].size();z++){
                int u=k[x][j];
                int v=k[y][z];
                ans=min(ans,num[u][v]+cnt[x][j]+cnt[y][z]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}