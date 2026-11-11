#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,x[2000005],m[2000005],d,cnt,vis[2000005];
int bfs(int l,int r){
	memset(m,0,sizeof m);
	memset(vis,0,sizeof vis);
	queue<pair<int,int>>q;
	q.push({l,1});
	vis[l]=true;
	while(!q.empty()){
		int top=q.front().first;
		int s=q.front().second;
		int len=r-top;
		q.pop();
		if(top==r){m[s]++,vis[top]=false;continue;}
		for(int i=top+1;i<=n;i++)
			if(x[i]-x[top]<=d&&!vis[i]){
				q.push({i,s+1});
				if(i!=r)vis[i]=true;
			}
	}
	for(int i=1;i<=n;i++)
		if(m[i]!=0)return m[i];
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(bfs(i,j)==2)cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}//ÎÒ*****£¬Ì«***ÄÑÁË£¬**£¿£¿£¿£¿£¿10 ~ 20pts 17:00
