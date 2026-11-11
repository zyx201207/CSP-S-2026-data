#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],st[N],top=0;
bool vis[N];
inline void solve(int x){
	for(int i=x;i<=n;i++){
		int now=a[i];
		if(vis[now]){
			while(top>0&&st[top]!=now){
				vis[st[top]]=0;
				top--;
			}
			top--;
		}
		vis[now]=1;
		st[++top]=now;
	}
	while(top>0){
		ans[st[top]]++;
		vis[st[top]]=0;
		top--;
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';

	return 0;
}

