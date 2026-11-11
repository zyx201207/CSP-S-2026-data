#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,d;
int x[2000010];
int dis[5010],vis[5010];
void solve1(){
	int c;
	cin>>n>>d;
	int aa=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		c=a-aa;
		aa=a;
	}
	c=abs(c);
	if(c>=d){
		cout<<0<<endl;
		return ;
	}
	d/=c;
	int ans=0;
	ans=n-(2*d)+1;
	cout<<max((long long)0,ans)<<endl;
}

int bfs(int a){
	int cnt=0;
	queue<int> q;
	dis[a]=0;
	q.push(a);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d) break;
			//cout<<i<<" "<<dis[i]<<" "<<dis[u]+1<<endl;
			if(dis[i]==dis[u]+1){
				//cout<<"ooo"<<i<<" "<<u<<endl;
				vis[i]+=vis[u];
				continue;
			} 
			if(dis[i]!=0) continue;
			//cout<<"&&"<<i<<" "<<u<<" "<<dis[i]<<"="<<dis[u]+1<<endl;
			dis[i]=dis[u]+1;
			vis[i]=vis[u];
			q.push(i);
		}
	} 
	//cout<<endl;
	for(int i=1;i<=n;i++){
		//cout<<vis[i]<<" ";
		if(vis[i]==2){
			cnt++;
			//cout<<i<<" ";
		} 
	}
	//cout<<endl<<endl;
	return cnt;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<x[i]+1000000000000000000<<" ";
//	}
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[j]=0,vis[j]=1;
		ans+=bfs(i);
		//cout<<"##"<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c<=10) solve();
		if(c==12 || c==11) solve1();
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
fc migrate.out migrate
11 1
10 22
0 7 14 21 28 35 42 49 56 63
*/