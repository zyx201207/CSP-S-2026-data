#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int ax[2000001],f[2000001],ji[2000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout)
	int c,t,n,d;
	cin>>c>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>ax[i];
		}
		int ans=0;
		for(int u=1;u<=n-3;u++){
			memset(f,127,sizeof(f));
			memset(ji,0,sizeof(ji));
			f[u]=0;
			for(int i=u;i<=n;i++){
				for(int j=i+1;ax[j]-ax[i]<=d;j++){
					if(f[j]==f[i]+1) ji[j]++;
					else f[j]=min(f[j],f[i]+1);
				}
			}
			sort(ji+1,ji+n+1);
			for(int i=1;i<=n;i++){
				if(ji[i]>1) break;
				else if(ji[i]==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
}