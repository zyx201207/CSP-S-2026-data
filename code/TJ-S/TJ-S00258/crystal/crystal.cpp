#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define PLL pair<LL,LL>
#define mp make_pair
#define mod ((LL)1e9+7)
#define inf ((LL)0x3f3f3f3f3f3f3f3f)
#define esp ((long double)1e-7)
#define len(x) ((LL)(x.size()))
inline LL mo(const LL x){return x-x/mod*mod;}
inline LL mo(const LL x,const LL p){return x-x/p*p;}
inline LL _mo(const LL x,const LL p){return mo(mo(x,p)+p,p);}
#define N ((LL)5e5+7)
LL n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;++i){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(LL l=1,r=1,num=1,cnt=a[1];r<=n;){
		while(a[r]*num-cnt>m){
			--num;
			cnt-=a[l];
			++l;
		}
		ans=max(ans,num);
		++r;
		++num;
		cnt+=a[r];
	}
	cout<<ans;
	return 0;
}
