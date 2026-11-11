#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5005],dis[5005][5005],cnt[5005][5005],ans;
void dfs(int now,int beg,long long dist){
	if (dis[beg][now]==-1)
	  dis[beg][now]=dist;
	if (dist>dis[beg][now])
	  return ;
	if (dist==dis[beg][now])
	  cnt[beg][now]++;
	if (now==n-1)
	  return ;
	int nxt=upper_bound(x,x+n,x[now]+d)-x-1;
	for (int i=nxt;i>=now+1;i--)
	  dfs(i,beg,dist+1);
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for (int i=0;i<n;i++){
			for (int j=i;j<n;j++){
				cnt[i][j]=0;
				dis[i][j]=-1;
			}
		}
		for (int i=0;i<n;i++)
		  cin>>x[i];
		for (int i=0;i<n;i++)
		  dfs(i,i,0);
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++)
			  ans+=(cnt[i][j]==2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
