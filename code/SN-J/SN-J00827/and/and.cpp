//姓名：张邦寒  准考证号：SN-J00827 学校：西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ll maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	ll ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
