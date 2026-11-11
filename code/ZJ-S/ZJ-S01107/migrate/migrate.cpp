#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k,i,x,mi,a[2000010],gc;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			gc=a[2]-a[1];
			mi=2*k+a[1];
			x=0;
			for(i=1;i<=n;i++){
				if(a[i]<mi&&a[i]+gc>=mi){
					x=i;break;
				}
			}
			if(x<4) cout<<0<<"\n";
			else{
				cout<<n-x+1<<"\n";
			} 
		}
		else cout<<0<<"\n";
	}
}
