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

int n;
ll m,a[N],s[N];

bool MST;
int main(){
  fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  
//  freopen("crystal4.in","r",stdin);
  
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  
  read(n),read(m);
  for(int i=1;i<=n;++i)read(a[i]);
  
  sort(a+1,a+n+1);
  for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
  
  int ans=1;
  
  for(int i=1;i<=n;++i){
    int l=1,r=i,p=i;
    while(l<=r){
      int mid=(l+r)>>1;
      if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)p=mid,r=mid-1;
      else l=mid+1;
    }
    cmax(ans,i-p+1);
  }
  
  printf("%d\n",ans);
  
  return 0;
}
