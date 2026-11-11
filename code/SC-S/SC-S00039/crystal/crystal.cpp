#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=1e5+10;
int n,m,a[N],ans;
void dfs(int x,int b[]){
	if(x>m){
		priority_queue<int,vector<int>,greater<int>> q;
//		cout<<"{";
//		for(int i=1;i<=n;++i)cout<<b[i]<<',';
//		cout<<"}";
		int t=n;
		for(int i=1;i<=n;++i)q.push(b[i]);
		while(q.size()){
			int t1=q.top();
			q.pop();
			int t2=q.top();
			q.pop();		
			if(t1!=t2)break;
			else{
				t--;
				q.push(t1+t2);
			}
		}
//		cout<<n-t+1<<endl;
		ans=max(ans,n-t+1);
		return;
	}
	int c[n+1];
	for(int i=1;i<=n;++i)c[i]=b[i];
	for(int i=1;i<=n;++i){
		c[i]++;
		dfs(x+1,c);
		c[i]--;
	}
}
void solve_bl(){
	dfs(1,a);
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=5&&m<=10)solve_bl();
	return 0;
}