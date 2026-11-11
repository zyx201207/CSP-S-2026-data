#include<bits/stdc++.h>
using namespace std;
long long x[2000006],c,t,n,d;
long long l,r,flag,ans,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		flag=0;
		ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) continue;
				for(long long z=i+1;z<j;z++){
					if(x[z]-x[i]>d) break;
					if(x[j]-x[z]>d) continue;
					cnt++;
				}
				if(cnt==2){
					ans++;
				}
				cnt=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
