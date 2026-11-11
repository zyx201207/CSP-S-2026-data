#include<iostream>
#include<vector>
#define int long long
using namespace std;
struct node{
    int idx,val;
};
int rd(){
    char c=getchar_unlocked();
    int res=0,f=1;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*f;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd();n=rd();m=rd();d=rd();q=rd();
    vector<vector<int>> f(n+1,vector<int> (n+1,1e18));
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }
    vector<int> w(m+1,0);
    vector<vector<node>> way(m+1);
    for(int i=1;i<=m;i++){
        w[i]=rd();
    }
    for(int i=1;i<=n;i++){
        int k;
        k=rd();
        for(int j=1;j<=k;j++){
            int x,val;
            x=rd();val=rd();
            way[x].push_back({i,val});
        }
    }
    for(int i=1;i<=m;i++){
        int len=way[i].size();
        for(int j=0;j<len;j++){
            for(int k=j+1;k<len;k++){
                f[way[i][k].idx][way[i][j].idx]=f[way[i][j].idx][way[i][k].idx]=min(f[way[i][j].idx][way[i][k].idx],way[i][j].val+way[i][k].val);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                f[j][i]=f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
                f[j][i]=f[i][j]=min(f[j][k]+f[k][i],f[i][j]);
            }
        }
    }
    while(q--){
        int x,y;
        x=rd();y=rd();
        int lenx=way[x].size(),leny=way[y].size();
        int ans=1e18;
        for(int i=0;i<lenx;i++){
            for(int j=0;j<leny;j++){
                ans=min(ans,way[x][i].val+way[y][j].val+f[way[x][i].idx][way[y][j].idx]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
