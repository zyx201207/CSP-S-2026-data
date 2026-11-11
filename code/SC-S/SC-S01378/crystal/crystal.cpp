#include<bits/stdc++.h>
using namespace std;

namespace IO{
	template<class T>inline T read(){
		T x=0;int f=1;char c=getchar();
		while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
		while('0'<=c && c<='9'){x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	template<class T>inline void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+'0');
		return;
	}
}using namespace IO;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>

const int N=5e5+10;
const int M=1e3+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll n,m,ans;
ll a[N],b[N];

inline bool ck(ll l,ll r,ll x){
	ll st=b[r]-b[l-1];
	ll ed=a[x]*(r-l+1ll);
	ll cost=ed-st;
	if(cost<=m)return 1;
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read<ll>();m=read<ll>();
	for(int i=1;i<=n;i++)a[i]=read<ll>();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(ll i=1,j=1;i<=n;j=++i){
		while(a[i]==a[i+1])i++;
		ll l=1,r=i,k=(l+r)>>1;
		while(l<r){
			if(ck(l,r,i))l-=k;
			else l+=k;
			k>>=1;
			if(l<=1){l=1;break;}
			if(l>=j){l=j;break;}
			if(!k)break;
		}
		ans=max(ans,i-l+1ll);
	}write<ll>(ans);
	return 0;
}