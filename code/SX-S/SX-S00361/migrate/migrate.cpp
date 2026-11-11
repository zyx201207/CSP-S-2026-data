#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,a[2000010],c,t,b[2000010],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			b[i]=1;
		}
		b[1]=0;
		for(ll i=2;i<=n;i++){
			for(ll j=i-1;j>=2;j--){
				if(a[i]-a[j]<=d&&b[j]!=0){
					b[i]++;
				}
				else break;
			}
		}
		for(ll i=1;i<=n;i++){

			if(b[i]-1==2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}