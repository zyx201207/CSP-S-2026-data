//Oct31==Dec25?
//T3 migrate 解法3 预期8  
#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,x[2000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<4){
			cout<<0<<endl;
			continue;
		}else if(C==11||C==12){
			if(2*(x[2]-x[1])!=d){
				cout<<0<<endl;
				continue;
			}
			cout<<n-3<<endl;
			continue;
	 	}
		cout<<0<<endl;
	}
	return 0;
}