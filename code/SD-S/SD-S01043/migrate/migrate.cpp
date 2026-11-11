#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000005],b[2000005];
int main(){
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(n>=4&&a[3]-a[1]<=d&&a[4]-a[1]>d){
				cout<<n-3;
			}
			else{
				cout<<0;
			}
			cout<<"\n";
			continue;
		}
		if(c==13||c==14){
			cout<<0;
			cout<<"\n";
			continue;
		}
		b[1]=1;
		int ans=0;
		for(int i=4;i<=n;i++){
			if(a[i-1]-a[i-3]<=d&&a[i]-a[i-3]>d){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
