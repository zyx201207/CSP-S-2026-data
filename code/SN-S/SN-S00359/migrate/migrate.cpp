//SN-S00359 张馨月 西安翱翔中学
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d1;
long long x[5005];
struct dat{
	long long zhi;
	int shu=0;
}d[5005];
bool vis[5005]={false};
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d1;
		for(int i=1;i<=n;i++){
			cin>>x[i]; 
		}
		if(x[1]<0){
			int fu=x[1];
			for(int i=1;i<=n;i++) x[i]=x[i]-fu;
		}
		for(int i=1;i<=n;i++){
			vis[x[i]]=true;
		}
		memset(d,-1,sizeof d);
		memset(vis,1,sizeof vis);
		d[x[1]].zhi=0;
		d[x[1]].shu=0;
		for(int j=1;j<=n;j++){
			long long xx=x[j];
			for(int i=1;i<=d1;i++){
				long long tox=xx+i;
				if(vis[tox]){
					//cout<<" 1x:"<<xx<<" tox:"<<tox<<" zhi:"<<d[tox].zhi<<" shu:"<<d[tox].shu<<endl;
					if(d[tox].zhi==-1){
						d[tox].zhi=d[xx].zhi+1;
						d[tox].shu=1;
					}
					else{
						if(d[tox].zhi==d[xx].zhi+1){
							d[tox].shu++;
						}
					}
					//cout<<" 2x:"<<xx<<" tox:"<<tox<<" zhi:"<<d[tox].zhi<<" shu:"<<d[tox].shu<<endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			//cout<<x[i]<<" "<<d[x[i]].zhi<<" "<<d[x[i]].shu<<endl;
			if(d[x[i]].shu==2) ans++;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
