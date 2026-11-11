#include <bits/stdc++.h>
#define int long long
using namespace std;
struct myst{
	int id,v;
};
int n,m,a[500005],s[300005],ans[300005];
vector<myst>v[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(s[a[i]]){
			ans[a[i]]++;
			v[i]=v[s[a[i]]+1];
			bool f=0;
			for(int j=0;j<v[s[a[i]]+1].size();j++){
				ans[v[s[a[i]]+1][j].id]+=v[s[a[i]]+1][j].v;
				if(v[s[a[i]]+1][j].id==a[i]){
					v[i][j].v++;
					f=1;
				}
			}
			if(!f){
				v[i].push_back({a[i],1});
			}
		}
		else{
			s[a[i]]=i;
			ans[a[i]]++;
			v[i]=v[i+1];
			for(int j=0;j<v[s[a[i]]+1].size();j++){
				ans[v[s[a[i]]+1][j].id]+=v[s[a[i]]+1][j].v;
				if(v[s[a[i]]+1][j].id==a[i]){
					v[i][j].v++;
					//f=1;
				}
			}
			v[i].push_back({a[i],1});
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
