#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N],f[10010][10010];
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			//f[i][i]=-1;
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					f[i][j]=1;
				}else{
					for(int k=j-1;k>i;k--){
						if(a[j]-a[k]<=d&&a[j]-a[k]!=a[k]-a[i]){
//							if(f[i][k]+1==f[i][j])f[i][j]++;
							f[i][j]=max(f[i][j],f[i][k]+1); 
						}
						if(a[j]-a[k]==a[k]-a[i]&&a[j]-a[k]<=d&&a[k]-a[i]<=d){
							if(a[j]-a[i]<2*d){
								f[i][j]+=1;
							}else f[i][j]=1;
							break;
						}
					}
				}
				//cout<<f[i][j]<<' ';
				if(f[i][j]==2){
					ans++;
				}
			} 
			
		}
		cout<<ans<<'\n';
	}
	return 0;
} 