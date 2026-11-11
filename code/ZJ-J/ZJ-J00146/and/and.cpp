#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1; ll ans=0;
	for(int b=30;b>=0;b--){
		ll mask=(1<<b); int cnt=0,L=0;
		for(int i=l;i<=n;i++){
			if(a[i]&mask){
				cnt++;
				if(!L) L=i;
			}
		}
		if(cnt>=m){
			ans+=mask; l=L;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
