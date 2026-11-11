#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int f[2000005];
int l[2000005];
int m[2000005];
long long u[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		m[n]=n;
		for(int i=n-1;i>=1;i--){
			if(a[i+1]-a[i]>d){
				m[i]=i;
			}
			else{
				m[i]=m[i+1];
			}
		}
		int k=1;
		for(int i=1;i<=n;i++){
			while(a[i]-a[k]>d)k++;
			l[i]=k;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			int k=i;
			for(int j=i+1;j<=m[i];j++){
				while(a[j]-a[k]>d)k++;
				f[j]=f[k]+1;
			}
			u[i]=u[i+1]=1;
			for(int j=i+2;j<=m[i];j++){
				u[j]=0;
				for(int k=max(l[j],i);k<=j-1;k++){
					if(f[l[j]]==f[k]){
						u[j]+=u[k];
					}
				}
				if(u[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
