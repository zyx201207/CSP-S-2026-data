#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,dis[2000010][3],t,w,mid,k,bao,j,dx[10],i,a[2000010],fx,sx,b[2000010],vis[2000010],ans;
priority_queue<int,vector<int>,greater<int> > q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			t=i;w=n;bao=i;
			while(t<=w){
				mid=(t+w)/2;
				if(a[mid]<=a[i]+d)t=mid+1,bao=mid;
				else w=mid-1;
			}
			b[i]=bao;
		}
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++)dis[i][0]=dis[i][1]=dis[i][2]=2e9,vis[i]=0;
			q.push(k);dis[k][0]=0;
			while(!q.empty()){
			fx=q.top();q.pop();
			if(fx>=n)continue;
			if(vis[fx])continue;
//			if(dis[fx][0]==dis[fx][1]&&dis[fx][1]==dis[fx][2])continue;
			vis[fx]=1;
			for(i=fx+1;i<=b[fx];i++){
				sx=i;
				dx[0]=dis[fx][0]+1;
				dx[1]=dis[fx][1]+1;
				dx[2]=dis[fx][2]+1;
				dx[3]=dis[i][0];
				dx[4]=dis[i][1];
				dx[5]=dis[i][2];
				sort(dx,dx+6);
				dis[sx][0]=dx[0];
				dis[sx][1]=dx[1];
				dis[sx][2]=dx[2];
				q.push(sx);
			}
		}
		for(i=1;i<=n;i++)
			if(dis[i][0]==dis[i][1]&&dis[i][0]!=dis[i][2])ans++;
		}
		cout<<ans<<"\n";ans=0;
	}
	return 0;
}

