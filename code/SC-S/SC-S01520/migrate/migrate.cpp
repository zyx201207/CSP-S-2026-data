#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,a[2000005];
long long ans,l[2000005],r[2000005],L[2000005],R[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>=11&&c<=12){
		while(T--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(n<=2){
				cout<<"0\n";
				continue;
			}
			int o=a[2]-a[1];
			o=d/o;
			if(o==0){
				cout<<"0\n";
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+o*2-1<=n)ans+=o-1;
				else if(i+o+1<=n)ans+=n-o-i;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		long long U=0,cv;
		for(int i=1;i<=n;i++)if(a[i]<=a[1]+d&&a[n]<=a[i]+d)U++,cv=i;
		if(U>1){
			ans=n;
			ans=(ans-U)*(ans-U-1)/2;
			cout<<ans<<"\n";
		}
		ans=0;
		bool re;
		for(int i=1;i<cv;i++){
			re=0;
			for(int j=cv+1;j<=n;j++){
				if(a[j]-a[i]>d){
					re=1;
					ans+=n-j+1;
					break;	
				}
			}
			if(!re)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}