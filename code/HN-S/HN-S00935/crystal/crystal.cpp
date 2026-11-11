#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
typedef long long ll;
ll n,m,a[MAXN],sum[MAXN];
map<ll,int> mp;
int ans;

inline void read(ll& x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

int get_sum(ll x){
	int cnt=0;
	ll tmpm=m;
	int pos=lower_bound(a+1,a+n+1,x)-(a+1);
	for(;pos>=1;pos--){
		if(tmpm-(x-a[pos])<0)break;
		tmpm-=(x-a[pos]);
		++cnt;
	}
	return cnt+mp[x];
}

void solve1(){
    for(int i=1;i<=n;i++)ans=max(ans,get_sum(a[i]));
}

bool P(int b,int e){
	unsigned long long res1=e-b+2,res2=e-b+1;
	if(res1&1ll)res2>>=1ll;
	else res1>>=1ll;
	if(res1>m||res2>m)return 0;
	return (res1*res2)<=m;
}

int get_sum2(ll x){
	int cnt=0;
    int pose=lower_bound(a+1,a+n+1,x)-(a+1);
	int l=1,r=pose,mid,posb=pose;
	while(l<=r){
		mid=l+r>>1;
		if(P(mid,pose))posb=min(posb,mid),r=l-1;
		else l=r+1;
	}
	return pose-posb+1+mp[x];
}

void solve2(){
	for(int i=1;i<=n;i++)ans=max(ans,get_sum2(a[i]));
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	
	if(n<=5000)solve1();
	else solve2();
	cout<<ans;
	return 0;
}
