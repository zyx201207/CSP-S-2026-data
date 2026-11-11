#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,dis,a[2000005];
		cin>>n>>dis;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int d=(a[n]-a[1])/(n-1);
		int x=dis/d;
		if(dis<d*2 || dis>(n-1)*d) cout<<0<<endl;
		else cout<<n-x-1<<endl;
	}
	return 0;
}
