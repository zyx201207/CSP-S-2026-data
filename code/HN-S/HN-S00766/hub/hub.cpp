#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k,x,y;
vector<int> ans;
vector<int> v[1000005],ipt[1000005];
static inline void dfs(int id,int lst,int depth){
	if((lst==-1&&ipt[id].size()==0)||(lst!=-1&&ipt[id].size()==1)){
		ans.push_back(depth);
		return;
	}
	for(const int&i:ipt[id]){
		if(i==lst) continue;
		v[id].push_back(i),dfs(i,id,depth+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k,ans.clear();
		for(int i=1;i<=n;i++)
			v[i].clear(),ipt[i].clear();
		for(int i=1;i<=n-1;i++){
			cin>>x>>y;
			ipt[x].push_back(y);
			ipt[y].push_back(x);
		}
		dfs(1,-1,1);
		sort(ans.begin(),ans.end(),greater<int>());
		cout<<min(k,ans[0]+ans[1])<<" ";
	}
	return 0;
}
