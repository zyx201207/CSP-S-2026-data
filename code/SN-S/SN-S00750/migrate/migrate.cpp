#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7;
ll x[N];
ll cha[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cha[i]=x[i]-x[i-1];
	}
	int ok=0;
	if(d==1)cout<<0<<'\n';
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cha[i]);
		}
		if((cha[i]+cha[i+1]<=d and cha[i+2]<d ) and (cha[i+1]+cha[i+2]<=d and cha[i]<d))cout<<i; 
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
} 
