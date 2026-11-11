#include<bits/stdc++.h>
#define int long long
using namespace std;
long long cc,testcase,n,d,a[2000005],cnt,minn;
bool vis[2000005];
inline void dfs(int now,int tar,int u,int v){
	if(now==tar+1){
		int ccnntt=0;
		for(int i=u+1;i<v;i++){
			ccnntt+=vis[i];
		}
		if(ccnntt+1>minn){
			return;
		}
		int lst=a[u];
		vis[v]=1;
		for(int i=u+1;i<=v;i++){
			if(!vis[i]){
				continue;
			}
			if(a[i]-lst>d){
				return;
			}
			lst=a[i];
		}
		cnt++;
		return;
	}
	vis[now]=0;
	dfs(now+1,tar,u,v);
	vis[now]=1;
	dfs(now+1,tar,u,v);
	return;
}
inline bool check(int u,int v){
	//从 u 到 v 有几条合法路径 
	int res=a[u],pos=u+1;
	minn=1;
	while(pos+1<=v){
		if(a[pos+1]-a[pos]>d){
			break;
		}
		if(res+d>=a[pos]&&res+d<a[pos+1]){
			minn++;
			res=a[pos];
		}
		else{
			pos++;
		}
	}
//	cout<<u<<"->"<<v<<":minn="<<minn<<",cnt=";
	memset(vis,0,sizeof(vis));
	cnt=0;
	dfs(u+1,v-1,u,v);
//	cout<<cnt<<endl;
	if(cnt==2){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>testcase;
	while(testcase--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
//					cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
//		cout<<"----------------------------"<<endl;
	}
	return 0;
}
