#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		int now[500005];
		memset(now,0,sizeof(now));
		for(int j=i;j<=n;++j){
			bool ok=false;
			for(int k=1;k<=n;++k){
				if(now[k]==0)break;
				if(now[k]==a[j]){
					ok=true;
					for(int ii=k;ii<=n;++ii){
						now[ii]=0;
						if(!now[ii+1])break;
					}
					now[k]=a[j];
					break;
				}
			}
			if(!ok){
				for(int k=1;;k++){
					if(now[k]==0){
						now[k]=a[j];
						break;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(now[j]==0)break;
			else ans[now[j]]++;
		}
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	cout<<endl; 
	return 0;
}
