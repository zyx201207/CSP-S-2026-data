#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num=5*1e5;
ll n,m,a[num],cnt[num],q[num];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	memset(cnt,0,sizeof cnt);
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<n;++i)
		cin>>a[i];
	for(ll i=0;i<n;++i){
		memset(q,0,sizeof q);
		ll l=i,r=i;
		for(ll j=i;j<n;++j){
			ll flag=true,ch;
			for(ll k=0;k<=r;++k)
				if(a[j]==q[k]){
					flag=false;
					ch=k;
				}
			if(!flag)
				r=ch;
			else
				++r;
			q[r]=a[j];
		}
		for(ll j=l;j<=n+3;++j){
			++cnt[q[j]];
		}
	}
	for(ll i=1;i<=m;++i){
		cout<<cnt[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}