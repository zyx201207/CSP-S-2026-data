#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
#define M 300005

int n,m,a[N],vis[M],ans[M],cnt;
stack<int> s;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;++j){
			if(vis[a[j]]){
				while(!s.empty()){
					vis[s.top()]--;
					if(s.top()==a[j]){
						s.pop();
						break;
					}
					else s.pop();
				}
				vis[a[j]]=0;
			}
			s.push(a[j]);
			vis[a[j]]++;
		}
		while(!s.empty()){
			int t=s.top();
			ans[t]++;
			s.pop();
		} 
	} 
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
