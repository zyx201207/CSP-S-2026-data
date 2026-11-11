#include <bits/stdc++.h>
using namespace std;
bool vis[500005];
int tmd[500005],sta[500005],tme[500005];
vector<pair<int,int> > e[500005];
int jl=0x3f3f3f3f;
void dfs(int st,int ed,int nw,int len) {
	if(nw==ed) {
		jl=min(jl,len);
	}
	vis[nw]=1;
	for(auto i:e[nw]) {
		if(!vis[i.first]) {
			dfs(st,ed,i.first,len+i.second);
		}
	}
	vis[nw]=0;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>tmd[i];
	}
	for(int i=1; i<=n; i++) {
		int km;
		cin>>km;
		for(int j=1; j<=km; j++) { //先输入
			cin>>sta[j];
			cin>>tme[sta[j]];
		}
		for(int j=1; j<=km-1; j++) { //全排列建图
			for(int k=j+1; k<=km; k++) {
				e[sta[j]].push_back(make_pair(sta[k],tme[sta[j]]+tme[sta[k]]));
				e[sta[k]].push_back(make_pair(sta[j],tme[sta[j]]+tme[sta[k]]));
			}
		}
	}
	if(c<=11||c>=16) { //深搜所有路径
		while(q--) {
			memset(vis,0,sizeof vis);
			jl=0x3f3f3f3f;
			int st,ed;
			cin>>st>>ed;
			dfs(st,ed,st,0);
			cout <<jl+tmd[st]+tmd[ed]<<"\n";
		}
	} else {
		while(q--) {
			memset(vis,0,sizeof vis);
			int st,ed;
			cin>>st>>ed;
			queue<int>q;
			q.push(st);
			vis[st]=1;
			int len=0;
			while(!q.empty()) {
				int dk=q.front();
				q.pop();
				for(auto i:e[dk])
				{
					if(vis[i.first])
					{
						continue;
					}
					len+=i.second;
					vis[i.first]=1;
					if(i.first==ed)
					{
						cout <<len+tmd[st]+tmd[ed]<<"\n";
						break;
					}
					else
					{
						q.push(i.first);
					}
				}
			}
		}
	}
	return 0;
}
