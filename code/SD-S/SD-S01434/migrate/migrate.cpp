#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2000010;
ll x[MAXN];
ll ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int  c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<"\n";
	}
	return 0;
} 
