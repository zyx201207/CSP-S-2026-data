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

const int N=2e6+5;

int sub,T;

int n;
ll x[N],d,L[N],R[N];

int pre[N],nxt[N];

namespace solve1{
  void main(){
    ll res=0;
    
//    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)
//      if(x[j]-x[i]<=d){
//        printf("(%d,%d)\n",i,j);
//        
//      }

//    for(int i=1;i<=n;++i)
//      pre[i]=lower_bound(x+1,x+n+1,x[i]-d)-x,
//      nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;

    for(int i=1,j=1;i<=n;++i){
      while(x[i]-x[j]>d)j++;
      pre[i]=j;
    }
    for(int i=n,j=n;i>=1;--i){
      while(x[j]-x[i]>d)j--;
      nxt[i]=j;
    }
    
    R[n+1]=0;
    for(int i=n;i>=2;--i){
      int j=nxt[i-1]+1;
      int b=nxt[i];
      
      if(j<=b)R[i]=R[b]+(b-j+1);
      else R[i]=0;
      
//      printf("R[%d]=%lld\n",i,R[i]);
    }
    
    L[0]=0;
    for(int i=1;i<n;++i){
      int j=pre[i+1]-1;
      int b=pre[i];
      
      if(b<=j)L[i]=L[b]+(j-b+1);
      else L[i]=0;
      
//      printf("L[%d]=%lld\n",i,L[i]);
    }
    
    for(int p=1;p<=n;++p)if(x[n]-x[p]>d){
      int b=nxt[p];
      int a=b-1;
      if(a<=p)continue;
      
      int yl=b+1;
      if(a>p)yl=nxt[a-1]+1;
      int yr=nxt[a];
      
      
      if(yl<=yr){
//        printf("%d : (%d,%d)\n",p,yl,yr);
      
        res+=yr-yl+1;
      
        int cl=!(p>1&&x[a]-x[p-1]<=d),cr=!(yr<n&&x[yr+1]-x[b]<=d);
          
        if(cl)res+=L[p]*(yr-yl+1);
        if(cr)res+=R[yr];
        if(cl&&cr)res+=L[p]*R[yr];
        
//        printf("(%d,%d,%lld)\n",cl,cr,res);
        
      }
      
    }
    
    printf("%lld\n",res);
    return;
  }
}

void solve(){
  read(n),read(d);
  for(int i=1;i<=n;++i)read(x[i]);
  
  solve1::main();
}

bool MST;
int main(){
  fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  
//  freopen("migrate6.in","r",stdin);
  
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  
  read(sub),read(T);while(T--)solve();
  
  return 0;
}
