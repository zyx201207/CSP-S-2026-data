#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int T,c;
int n,d;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			int cha=x[2]-x[1];
			int temp=d/cha;
			if(temp<=1) cout<<"0\n";
			else cout<<max(n+1-2*temp,0ll)<<'\n';
		}
	}
	return 0;
}

