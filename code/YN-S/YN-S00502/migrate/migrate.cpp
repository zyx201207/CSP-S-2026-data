#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int k=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)k=a[i]-a[i-1];
		}	
		int q=d/k;
		for(int i=q+1;i<=n;i++){
			if((i-q-1)%q==0)continue;
			ans+=n-i;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}