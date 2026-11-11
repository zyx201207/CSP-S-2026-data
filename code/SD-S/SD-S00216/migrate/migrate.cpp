#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[100001];
long long g[10010][10010];
long long ccc[100100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(long long  i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i][j]++;
				}
			} 
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				ccc[i]+=g[i][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			if(ccc[i]==2)ans++;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=0;
			ccc[i]=0;
		}
	}
	
	return 0;
} 
