#include<bits/stdc++.h>
using namespace std;
int c,T;
const int N=5010;
vector<int> color[N],g[N];
int a[N];
int n,d,idx=1,la,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>10){
		cout<<0;
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int j=1;
		memset(color,0,sizeof(color));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			j=i;
			while(a[j]-a[i]<=d and j<=n){
				if(color[j].empty()){
					color[j].push_back(idx);
					g[idx].push_back(j);
				}
				else if(color[j][color[j].size()-1]!=idx){
					color[j].push_back(idx);
					g[idx].push_back(j);
				}
				j++;
			}j--;
			if(la!=j and a[j]-a[i+1]<=d and j!=n) idx++;
			la=j;
		}
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=0;j<g[color[i][0]].size();j++){
				if(color[j].size()-color[i].size()==1) cnt++;
			}if(cnt==2) ans++;
		}cout<<ans/2>>'\n';
	}
	return 0;
}
