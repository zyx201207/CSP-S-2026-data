#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int x[200010];
bool check(int n,int d,int u,int v){
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	if(15<=c&&c<=18){
		while(t--){
			ll n,d;cin>>n>>d;
			ll cnt=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			ll cha=x[2]-x[1];
			if(d<cha){
				cout<<0;
				continue;
			}else{
				
			}
		}
	}
	return 0;
}
