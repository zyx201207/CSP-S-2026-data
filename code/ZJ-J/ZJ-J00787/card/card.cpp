#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
stack<int> qp;
int n,m;
int a[maxn];
bool vis[maxn];
int ans[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!qp.empty()&&qp.top()!=a[j]){
					vis[qp.top()]=0;
					qp.pop();
				}
			}else{
				qp.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!qp.empty()){
			ans[qp.top()]++;
			//cout<<qp.top()<<" ";
			qp.pop();
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
