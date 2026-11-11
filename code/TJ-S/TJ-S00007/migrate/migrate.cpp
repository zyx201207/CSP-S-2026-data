#include<bits/stdc++.h>

using namespace std;
#define int long long
int t,n,d,a[5005][5005],x[2000005],c,minn[5005][5005];
struct st{
	int x,b;
};
void bfs(int qd){
	queue<st> q;
	q.push({qd,0});
	while(!q.empty()){
		st t=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(x[i]-x[t.x]>d)break;
			if(minn[qd][i]<t.b+1)continue;
			if(minn[qd][i]==t.b+1){
				q.push({i,t.b+1});
				a[qd][i]++;
				continue;
			}
			minn[qd][i]=t.b+1;
			a[qd][i]=1;
			q.push({i,t.b+1});
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=0;
				minn[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(a[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
