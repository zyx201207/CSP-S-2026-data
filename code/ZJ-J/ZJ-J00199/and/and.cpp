#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans,t,x,s;
vector<long long>g[2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;t=0;
	for(i=1;i<=n;i++)cin>>x,g[t].push_back(x);
	for(i=30;i>=0;i--){
		s=0;
		g[t^1].clear();
		for(j=0;j<g[t].size();j++)
			if((g[t][j]>>i)&1)s++;
		if(s>=m){
			ans=ans|(1<<i);
			for(j=0;j<g[t].size();j++)
				if((g[t][j]>>i)&1)g[t^1].push_back(g[t][j]);
			t=t^1;
		}
	}
	cout<<ans;
	return 0;
}