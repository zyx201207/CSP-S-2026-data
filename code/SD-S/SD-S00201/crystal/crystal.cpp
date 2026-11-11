#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N=5e5+10,inf=1e12+10;
ll n,m;
ll a[N],pre[N];
ll maxn=-inf,minn=inf;
bool judge=1;
ll ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);minn=min(minn,a[i]);maxn=max(maxn,a[i]);
	}
	int diff=a[1]-a[0];
	for(int i=1;i<n;++i){
		if(a[i]-a[i-1]!=diff){
			judge=0;
		}
	}
	if(judge==1){
		int i=0;int now=0;
		while(1){
			if(now+i*diff>m){
				cout<<i;
				return 0;
			}
			if(i>=n){
				cout<<n;return 0;
			}
			now=now+(i*diff);i++;
		}
	}
	//
		sort(a,a+n);
		ll now=0;ll res=0;
		for(int i=minn;i<=maxn;++i){
			for(int j=0;j<n;++j){
				if(a[j]<=i){
					if(now+(i-a[j])<=m){
						res++;now=now+(i-a[j]);
					}
				}
			}
			ans=max(ans,res);//cout<<i<<" "<<res<<endl;
			now=0,res=0;
		}
		cout<<ans;return 0;
	//}
	return 0;
}

