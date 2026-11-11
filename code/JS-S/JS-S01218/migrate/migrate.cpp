#include <bits/stdc++.h>
using namespace std;

void open_file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

using ll=long long;
constexpr int N=2e6+5;
int c,T,n,ans;
int vis[N],num[N];
ll d,a[N];

void dfs(int p,int cnt){
	if (cnt==vis[p]){
		++num[p];
		if (num[p]==2) ++ans;
		else if (num[p]==3) --ans;
	} else if (cnt<vis[p]){
		vis[p]=cnt;
		if (num[p]==2) --ans;
		num[p]=1;
	}else return ;
	int i=upper_bound(a+1,a+n+1,a[p]+d)-a-1;
	for (;i>p;--i)
		dfs(i,cnt+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	open_file("migrate");
	cin>>c>>T;
	while (T--){
		cin>>n>>d;
		for (int i=1;i<=n;++i)
			cin>>a[i];
		for (int i=1;i<=n;++i){
			for (int i=1;i<=n;++i)
				num[i]=0,vis[i]=INT_MAX;
			dfs(i,0);
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
