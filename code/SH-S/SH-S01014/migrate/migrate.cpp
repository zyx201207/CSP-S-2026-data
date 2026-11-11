#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d;
int x[N];
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int gongcha=x[2]-x[1];
	int t=d/gongcha;
	
	if(t>2){
		cout<<"0\n";
		return;
	}
	int len=t+1;
	cout<<n-len<<"\n";	
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>T;
	while(T--)solve();
	
}
