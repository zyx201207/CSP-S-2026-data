#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m,a[500010],d[500010],ans[500010];
bool t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(ll i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			d[i] = a[i];
			t[a[i]] = 1;
			if(t[a[i]]){
				d[500010] = {0},d[i] = a[i];
			}
		}
		for(ll i = 1;i<=m;i++)
			for(ll j = 1;j<=m;j++)
				if(d[j]==i)
					ans[d[j]]++;
	}
	for(ll i = 1;i<=m;i++)
		printf("%lld",ans[i]);
	return 0;
}
