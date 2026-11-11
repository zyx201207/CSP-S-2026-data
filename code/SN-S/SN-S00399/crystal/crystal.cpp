#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n,ans=-0x3f3f3f3f;
ll m,a[maxn],c[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=a[i]-a[1];
	ll s=0;
	int now=n;
	for(int i=n-1;i>=1;i--){
		s+=c[now]-c[i];
		while(s>m){
			s-=(c[now]-c[now-1])*(now-i);
			now--;
		}
		ans=max(ans,now-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}
