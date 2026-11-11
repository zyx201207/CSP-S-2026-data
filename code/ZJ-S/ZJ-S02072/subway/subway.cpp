#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll inf=1e18;
typedef pair<int,int> PA;
int c,n,m,d,q;
int w[M];
vector< PA >vec[M];
ll f[N][N];
int getint(){
    char st=getchar();
    int res=0;
    for(;st<'0'||st>'9';st=getchar());
    for(;st>='0'&&st<='9';st=getchar())res=res*10+(st&15);
    return res;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=getint(),n=getint(),m=getint(),d=getint(),q=getint();
    for(int i=1;i<=m;i++){
        w[i]=getint();
    }
    for(int i=1,k,a,t;i<=n;i++){
        k=getint();
        while(k--){
            a=getint(),t=getint();
            vec[a].emplace_back(t,i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=(i==j?0:inf);
        }
    }
    for(int i=1;i<=m;i++){
        for(PA j:vec[i]){
            for(PA k:vec[i]){
                if(j.second==k.second)continue;
                f[j.second][k.second]=f[j.second][k.second]=min(f[j.second][k.second],(ll)(j.first+k.first));
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }    
    }
    int x,y;
    while(q--){
        x=getint(),y=getint();
        ll res=inf;
        for(PA i:vec[x]){
            for(PA j:vec[y]){
                res=min(res,f[i.second][j.second]+i.first+j.first);
            }
        }
        printf("%lld\n",res+w[x]+w[y]);
    }
    return 0;
}