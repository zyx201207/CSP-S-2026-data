#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T;
int x[2000005];
struct bb{
	int dz;//位置 
	int cd;//路径长度 
	int lj;//多少个 
}a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int n,d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		if(d==0||d==1){
			cout<<0<<'\n';
		}
		else{
			cout<<C+T+n-d<<'\n';
		}
	}
	return 0;
}
