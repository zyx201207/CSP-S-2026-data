#include<bits/stdc++.h>
using namespace std;
struct qq{
	int x,y,id;
}ans[2000001];
long long c,t,n,m,lmj[2000001],cnt[2000001],z,tot;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(ans,0,sizeof(ans));
		z=0;
		for(int i=1;i<=n;i++){
			cin>>lmj[i];
		}
		for(int e=1;e<=n;e++){
			memset(cnt,0,sizeof(cnt));
			for(int i=e;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(lmj[j]-lmj[i]<=m){
						if(cnt[j]==0||cnt[j]>cnt[i]+1){
							cnt[j]=cnt[i]+1;
						}
						else if(cnt[j]==cnt[i]+1){
							bool isn=0;
							for(int qwq=1;qwq<=z;qwq++){
								if(ans[qwq].x==lmj[e]&&ans[qwq].y==lmj[j]){
									isn=1;
									ans[qwq].id=1;
									break;
								}
							}
							if(isn==0){
								ans[++z].x=lmj[e];
								ans[z].y=lmj[j];
							}
						}
					}
				}
			}
		}
		int tot=0;
		for(int i=1;i<=z;i++){
			if(ans[i].id==0){
				tot++;
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
