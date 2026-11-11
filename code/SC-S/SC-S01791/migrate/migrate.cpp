#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],l;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			l=x[i]-x[i-1];
		}
		if(2*d<l)cout<<1<<'\n';
		else{
			int s=d/l*2;
			cout<<s<<' ';
			cout<<max(n-s+1,(int)0)<<'\n';
		}
	}
	return 0;
}