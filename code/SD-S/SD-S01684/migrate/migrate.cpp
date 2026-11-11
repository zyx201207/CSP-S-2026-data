#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+10;
int n,d;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t--){
		int a[N];
		cin>>n>>d;
		int o,s;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				o=a[i-1]-a[i-2];
				s=a[i]-a[i-1];
				if(s!=o){
					f=1;
				}
			}
		}
		if(!f){
			int y=a[2]-a[1];
			int u=d/y;
			int o=0;
			if(u==2){
				for(int i=n;i>3;i--){
					o+=i/3;
				}
				cout<<o<<endl;
			}
			else{
				cout<<o<<endl;
			}
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}

