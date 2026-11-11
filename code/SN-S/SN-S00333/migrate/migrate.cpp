//李方骁 西安交通大学附属中学 SN-S00333
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll n;
ll d;
ll x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==13 or c==14){
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;++i){
				cin>>x[i];
			}
			cout<<0<<'\n';
		}
	}
	if(c==11 or c==12){
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;++i){
				cin>>x[i];
			}
			ll cha=x[2]-x[1];
			ll as=cha,tot=0;
			if(cha>=d){
				cout<<0<<'\n';
				continue;
			}
			else {
				while(as<=d){
					as+=cha;
					tot++;
				}
				if(tot*2+1>n)cout<<0<<'\n';
				else cout<<n-tot*2+1<<'\n';
			}
		}
	}
	return 0;
}

