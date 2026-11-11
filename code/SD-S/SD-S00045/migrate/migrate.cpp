#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000006];
int main(){            
	freopen("migrate.in","r", stdin);
	freopen("migrate.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			long long n,d;
			cin>>n>>d;
			long long cha=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				cha=x[i]-x[i-1];
			}
			if(cha>d){
				cout<<0;
				continue;
			}
			long long kuayue=d/cha;
			kuayue*=2;
			cout<<n-kuayue<<"\n";
		}
		return 0;
	}
	return 0;
}
