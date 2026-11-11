#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n-3;i++){
			if(x[i+3]==x[i]+d+1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}