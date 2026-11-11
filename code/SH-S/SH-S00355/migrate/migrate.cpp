#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){	
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int flag=0;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>d){
				cout<<0<<"\n";
				flag=1;
				break;
			}
		}
		if(flag) break;
		
	}
}
