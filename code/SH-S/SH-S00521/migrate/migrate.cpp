#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5; 
int n,d;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int flag=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=2;i<n;i++){
			if(x[i]-x[i-1]!=x[i+1]-x[i])flag=1;
		}
		if(!flag){
			int a=x[2]-x[1];
			int k=d/a;
			int l=k+1,r=2*k-1;
			int ans=0;
			for(int i=l;i<=min(r,n);i++){
				int o=n-i+1;
				ans+=o;
			} 
			cout<<ans<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}
