#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,ans=0,a[1000001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int p=0;
		for(int i=1;i<=n;i++){
			int op=1;
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])>m)op=0;
			}
			if(op==1)p=i;
		}
		if(p!=0){
			for(int i=1;i<p;i++){
				for(int j=p+1;j<=n;j++){
					if((abs(a[i]-a[p-1])<=m&&abs(a[i]-a[p+1])>m)||(abs(a[i]-a[p+1])<=m&&abs(a[p-1]-a[j])>m))ans++;
				}
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
