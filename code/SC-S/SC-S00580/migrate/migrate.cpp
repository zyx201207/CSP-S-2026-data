#include<bits/stdc++.h>
using namespace std;
int a[2000005],p[10005][10005],pp[10005][10005];
int n,d,sss=0;
void dfs(int x,int y,int ans){
	if(ans==p[x][y]){
		pp[x][y]++;
		//cout<<x<<" "<<y<<'\n';
	}
	if(ans>p[x][y]) return;
	for(int i=y+1;i<=n;i++){
		if(a[i]-a[y]<=d){
			//cout<<x<<"->"<<i<<"/"<<ans<<'\n';
			dfs(x,i,ans+1);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			int kk=1,dx=a[i];
			for(int j=i;j<=n;j++){
				if(a[j]-dx>d){
					kk++;
					dx=a[j-1];
				}
				p[i][j]=kk;
				//cout<<i<<" "<<j<<" "<<p[i][j]<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
			//cout<<sum<<" ";
			for(int j=1;j<=n;j++){
				for(int u=1;u<=n;u++){
					if(pp[j][u]==2) sss++;
					pp[j][u]=0;
				}
			}
		}
		printf("%d\n",sss);
		sss=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				p[i][j]=0;
			}
		}
	}
	return 0;
} 