//姓名：张邦寒 学校：西安交通大学附属中学 准考证号：SN-S00335
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500100],at[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool ok=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) ok=false;
	}
	if(ok){
		ll ans=1;
		for(int i=1;i<n;i++){
			if(m>=i){
				m-=i;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	ok=true;
	for(int i=2;i<=n;i++){
		if(i==2) continue;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			ok=false;
			break;
		}
	}
	if(ok){
		ll ans=1;
		for(int i=n-1;i>=1;i--){
			if(m>=(a[n]-a[i])){
				ans++;
				m-=(a[n]=a[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	ll maxx=0;
	for(int i=1;i<=n;i++){
		ll ans=1,now=m;
		for(int j=i-1;j>=1;j--){
			if(now>=(a[i]-a[j])){
				now-=(a[i]-a[j]);
				ans++;
			}else break;
		}
		if(ans>maxx){
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
