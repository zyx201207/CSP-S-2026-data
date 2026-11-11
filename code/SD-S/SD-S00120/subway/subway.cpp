#include<bits/stdc++.h>
using namespace std;
bool MED;
template<typename T>inline void read(T &x){
  x=0;char c=getchar();int f=0;
  while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
  while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
  if(f)x=~x+1;
}

#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define pb push_back
#define eb emplace_back
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define se second
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(),(x).end()

template<typename T,typename U>inline void cmin(T &x,U y){if(y<x)x=y;}
template<typename T,typename U>inline void cmax(T &x,U y){if(y>x)x=y;}

const int N=5e5+5;
const int M=505;
const ll inf=4e18;

int sub,n,m,D,q;
ll w[N],f[M][M];
vector<PII> vec[N];

bool MST;
int main(){
  fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  
//  freopen("subway7.in","r",stdin);
  
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  
  read(sub),read(n),read(m),read(D),read(q);
  for(int i=1;i<=m;++i)read(w[i]);
  
  memset(f,0x3f,sizeof(f));
  
  for(int i=1;i<=n;++i){
    int k;read(k);
    while(k--){
      int a,t;read(a),read(t);
      vec[a].eb(i,t);
    }
  }
  
  for(int i=1;i<=n;++i)f[i][i]=0;
  
  for(int u=1;u<=m;++u)
    for(int i=0;i<SZ(vec[u]);++i)for(int j=i+1;j<SZ(vec[u]);++j){
      ll val=vec[u][i].se+vec[u][j].se;
      cmin(f[vec[u][i].fi][vec[u][j].fi],val);
      cmin(f[vec[u][j].fi][vec[u][i].fi],val);
    }
  
  for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
    cmin(f[i][j],f[i][k]+f[k][j]);
  
  while(q--){
    int u,v;
    read(u),read(v);
    
    
    ll res=inf;
    for(PII x:vec[u])for(PII y:vec[v])
      cmin(res,f[x.fi][y.fi]+x.se+y.se);
    res+=w[u]+w[v];
    
    printf("%lld\n",res);
  }
  
  return 0;
}
