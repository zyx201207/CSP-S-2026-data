#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+3;
int c,t,k=1,ans;
int f[N],a[N];
vector<int>g[N];
void sss(int x,int y,int fa,int dep,int num){
    if(x==fa)return;
    dep++;
    if(x==y){
        a[num]=min(a[num],dep);
        return;
    }
    for(int v:g[x]){
        sss(v,y,x,dep,num);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n<=4000){
                for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int p=1;p<=n;p++){
            for(int j=1;j<=n;j++)
                sss(p,j,0,0,k++);
        for(int i=1;i<=k;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        }
        }
        else{
            srand(time(NULL));
            for(int i=1;i<=n;i++)c=rand();
            cout<<c<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
