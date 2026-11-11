#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000005],a[305][305],p[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		int ans=0;
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=-1;
				p[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					a[i][j]=1;
					a[j][i]=1;
				}else{
					break;
				}
			}
		}
		for(int s=1;s<=n;s++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(s==i||s==j) continue;
					if(a[i][s]==-1||a[s][j]==-1){
						continue;
					}
					if(a[i][j]==-1){
						a[i][j]=a[i][s]+a[s][j];
					}
					else if(a[i][s]+a[s][j]<a[i][j]){
						a[i][j]=a[i][s]+a[s][j];
						p[i][j]=1;
					}
					else if(a[i][s]+a[s][j]==a[i][j]){
						p[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(p[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
