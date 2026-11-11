#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
int main(){
	    freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
		while(t--){
			memset(a,0,sizeof(a));
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
			cin>>a[i];
			}
			int cnt=a[2]-a[1];
			if(cnt>d){
			cout<<0<<endl;
			}
			else{
				int tot=d/cnt;
				int ans=(n-3)/tot+1;
				cout<<ans<<endl;
			}
		}
		return 0;
}
