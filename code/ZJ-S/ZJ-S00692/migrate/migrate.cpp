#include<iostream>
using namespace std;
int c,t,n,ans;
long long d;
struct node{
	int l,p;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(;t--;){
		cin>>n>>d,ans=0;
		long long x[n+5];
		node f[n+5][n+5];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j].l=0x3f3f3f3f,f[i][j].p=0;
			}
		}
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d)break;
				f[i][j].l=1,f[i][j].p=1;
			}
		}
		for(int k=2;k<n;k++){
			for(int i=1;i<k;i++){
				if(i==k)continue;
				for(int j=k+1;j<=n;j++){
					if(i==j||j==k)continue;
					if(f[i][j].l>f[i][k].l+f[k][j].l)f[i][j].l=f[i][k].l+f[k][j].l,f[i][j].p=f[i][k].p*f[k][j].p;
					else if(f[i][j].l==f[i][k].l+f[k][j].l)f[i][j].p+=f[i][k].p*f[k][j].p;
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j].p==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
