#include<bits/stdc++.h>
using namespace std;
int n;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(x[2]-x[1]>=d){
				cout<<0<<'\n';
			}else{
				cout<<n-3<<'\n';
			}
			continue;
		}
		if(c==13||c==14){
			long long ans=0,cnt=0;
			int a[n+10]={0};
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					cnt++;
					a[cnt]=i;
				}
			}
			if(cnt==2){
				ans+=n-7;
				ans+=(a[1]-1)*(n-a[2]+1);
			}else if(cnt==1){				
				ans+=n-6;
			}
			cout<<ans;
		}
	} 
	return 0;
}
