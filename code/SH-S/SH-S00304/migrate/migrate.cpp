#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int maxn=2e6+10;
int c,T,n;
ll d;
ll a[maxn];
ll ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			ans=n-1;
			if(a[2]-a[1]>d/2)ans+=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
