#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000006],s[2000006];
bool tepa=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	 cin>>c>>t;
	while(t--){
		long long ans=0;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		cin>>n>>d;
		long long ls;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>3&&a[i]-a[i-1]!=ls){
				tepa=0;
			}
			if(i>1)ls=a[2]-a[1];
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		bool wl=1;
		for(int i=2;i<=n;i++){
			s[i]=a[i]-a[i-1];
			if(s[i]<d)wl=0;
		}
		if(tepa){
			int dis1=d/ls;
			dis1=dis1*2-1;
			ans=n-dis1;
			if(dis1<=1)ans=0;
			if (ans<=0)ans=0;
			cout<<ans<<"\n";
			continue;
		}
		if(wl){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int k=i+2;k<=n;k++){
				if(a[k]-a[i]<=d)continue;
				if(a[k]-a[i]>2*d)break;
				int tj=0;
				for(int j=i+1;j<k;j++){
					if(a[k]-a[j]<=d&&a[j]-a[i]<=d)tj++;
				
					if(tj>2)break;
				}
				if(tj==2)ans++;
			}
		}
		cout<<ans<<"\n";
		
		
	}
	return 0;
}
