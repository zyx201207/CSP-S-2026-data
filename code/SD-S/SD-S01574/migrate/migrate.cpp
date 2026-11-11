#include<bits/stdc++.h>
using namespace std;
long long x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0,c[20005];
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		
		for(long long j=1;j<n;j++){
			long long pre[200005];
			pre[j-1]=0;
			for(long long i=j;i<n;i++){
				c[i]=x[i+1]-x[i];
				
				pre[i]=pre[i-1]+c[i];
				if(pre[i-1]<=d&&pre[i]>d){
					pre[i]=c[i];
					ans++;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
