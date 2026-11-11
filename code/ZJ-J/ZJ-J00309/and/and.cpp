#include<bits/stdc++.h>
using namespace std;
int n,m,ans,rec[200005],mx;
bool a[200005][30],vis;
queue<int>q,qq,qqq;
void pusher(){
	while(!qqq.empty()){
		q.push(qqq.front());
		qqq.pop();
	}
}
void query(){
	vis=true,ans=rec[qq.front()];
	qq.pop();
	while(!qq.empty()){
		int x=qq.front();
		ans&=rec[x];
		qq.pop();
	}
}
void bfs(int now){
	if(now==0)return;
	int len=q.size(),cnt=0;
	for(int i=1;i<=len;i++){
		int x=q.front();
		q.pop();
		if(a[x][now]==1)cnt++,qq.push(x);
		qqq.push(x);
	}
	if(cnt<m)pusher();
	else if(cnt==m){
		query();
		return;
	}
	else{
		while(!qq.empty()){
			q.push(qq.front());
			qq.pop();
		}
	}
	while(!qqq.empty())qqq.pop();
	bfs(now-1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>rec[i];
	for(int i=1;i<=n;i++){
		int temp=rec[i],cnt=0;
		while(temp){
			a[i][++cnt]=temp%2;
			temp/=2;
			mx=max(mx,cnt);
		}
	}
	for(int i=1;i<=n;i++)q.push(i);
	bfs(mx);
	if(vis)cout<<ans;
	else{
		ans=rec[q.front()];
		q.pop();
		for(int i=2;i<=m;i++){
			ans&=rec[q.front()];
			q.pop();
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}