/*
BFS版本一运行就电脑黑屏？？？
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int a[N];
int tans,ans;
int n,d;
int m_s;
void dfs(int x,int y,int s){
	if(x==y&&s==m_s){
		tans++;
		return;
	}
	if(s>=m_s){
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,s+1);
		}else{
			return;
		}
	}
}
void bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,0});
	while(!q.front().second==m_s){
		int pos=q.front().first;
		int s=q.front().second;
		for(int i=pos;i<=y;i++){
			if(a[i]-a[pos]<=d){
				q.push({i,s+1});
			}else{
				break;
			}
		}
	}
	while(!q.empty()){
		if(q.front().first==y){
			ans++;
		}
		q.pop();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//freopen("migrate.dbg","w",stderr);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		//cerr<<t<<":\n    "<<n<<" "<<d<<"\n    ";
		for(int i=1;i<=n;i++){
			cin>>a[i];
			//cerr<<a[i]<<" ";
		}
		//cerr<<"\n";
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				/*
				第一步:计算两点最近距离
				第二步:统计这两点最近距离的数量(好吧,只会用深搜)
				第三步:统计结果
				然后...不会了 
				*/
				//ss1
				m_s=0;
				int u=i;
				for(int k=i;k<=j;k++){
					if(a[k]-a[u]<=d&&(a[k+1]-a[u]>d||k==j)){
						u=k;
						m_s++;
					}
				}
				if(u!=j){
					continue;
				}
				//ss2
				tans=0;
				dfs(i,j,0);
				//ss3
				if(tans==2){
					ans++;
				}
				//cerr<<"    "<<i<<" "<<j<<" "<<m_s<<" "<<tans<<"\n";
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
