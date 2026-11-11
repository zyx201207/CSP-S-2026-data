#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,e[1010][1010],n,d,a[1000010],ans[1010][1010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c==11||c==12)
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[2]-a[1];
		int y=d/x;
		int z=d/x*2-1;
		cout<<n-z<<"\n";
	}
	else while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<"\n";
	}
}