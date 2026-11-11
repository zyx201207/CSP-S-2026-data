//16:38 来骗分喽……
//		这么吝啬，暴力只给 5pts 
//		图论题多测，The problem setter, I hate you.
//17:06 一百多行仅 5pts? 
//17:17 不做了，一个小时获得 0pts 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,k;
vector<int>t[1000005];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)t[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		t[u].push_back(v);
		t[v].push_back(u);
	}
//	if(c==1){//task 1 5pts
		vector<vector<int>>dist(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			queue<int>q;
			q.push(i);
			vector<bool>vis(n+1,false);
			vis[i]=true;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:t[u]){
					if(!vis[v]){
						vis[v]=true;
						dist[i][v]=dist[i][u]+1;
						q.push(v);
					}
				}
			}
		}
		int ans=n;
		for(int i=0;i<(1<<n);i++){
			int ck=__builtin_popcountll(i);
			if(ck!=k)continue;
			vector<int>co;
			vector<bool>ced(n+1,false);
			for(int j=0;j<n;j++){
				if(i&(i<<j)){
					ced[j+1]=true;
					co.push_back(j+1);
				}
			}
			queue<int>q;
			q.push(co[0]);
			vector<bool>vis(n+1,false);
			vis[co[0]]=true;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:t[u]){
					if(!vis[v]&&ced[v]){
						vis[v]=true;
						q.push(v);
					}
				}
			}
			bool flag=true;
			int s=0;
			for(int j:co){
				if(!vis[j]){
					s=j;
					flag=false;
					break;
				}
			}
			bool check=flag;
			if(!flag){
				for(int i=1;i<=n;i++)vis[i]=false;
				q.push(s);
				vis[s]=true;
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(int v:t[u]){
						if(!vis[v]&&ced[v]){
							vis[v]=true;
							q.push(v);
						}
					}
				}
				flag=true;
				for(int j:co){
					if(!vis[j]){
						flag=false;
						break;
					}
				}
				check=flag;
			} 
			if(!check)continue;
			int r=0;
//			cerr<<"\nco= ";
//			for(int j:co)cerr<<j<<' ';
			for(int i=1;i<=n;i++){
				int d=n;
				for(int j:co)
					d=min(d,dist[i][j]);
				r=max(r,d);
			}
//			cerr<<"\nr="<<r<<'\n';
			ans=min(ans,r);
		}
//		cerr<<"\nans=";
		cout<<ans<<'\n';
//	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1
2
*/
//0pts 
//总分 [108,132]pts 
//Hello everyone, I'm Xuzhaoqian123 (uid=1430229).
//I want to get 2= in CSP-S exam.
//But I solved T1 in 30 minutes, and I got only [8,32]pts in other time.
//This year, T1 is easy.
//So can I get 2=?
//I got [235,269]pts in CSP-J, and I want to get 1=.
//So, dear CCF, could you make my dream come true?
//I think my friend wangzhiqi1213 (uid=1239752) can get CSP-S 1=.
//I'll ask him, T1 is two-pointer, isn't it?
//And I'll tell him my score, ask him, could I win 2=?
//Hope his answer.
