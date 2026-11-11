#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,res,op;
vector<int> ans[2],a[40];
unordered_map<int,int> f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		f[x]=1;ans[op].push_back(x);
		for(int j=0;j<=30;j++)
			if(x&(1<<j))
				a[j].push_back(x);
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=0;j<a[i].size();j++){
			int x=a[i][j];
			if(f[x]==1)cnt++;
		}
		if(cnt>=m){
			res+=(1<<i);
			ans[1-op].clear();
			f.clear();
			for(int j=0;j<ans[op].size();j++)
				if(ans[op][j]&(1<<i))
					ans[1-op].push_back(ans[op][j]),f[ans[op][j]]=1;
			op=1-op;
		}
	}
	cout<<res;
	return 0;
}
