#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,y,z,s,d,h,o,tt,a[2000100],t,w,v[2000100],r[2000100],e[2000100],g[2000100];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>o>>tt;
	while(tt--){
		cin>>n>>m;
		vector<int> f[n+1];
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=2;i<=n;i++)
			for(j=i-1;j>=1;j--)
				if(a[i]-a[j]<=m) f[j].push_back(i);
				else break;
		for(i=1;i<=n-2;i++){
			memset(e,127,sizeof(e));
			memset(g,0,sizeof(g));
			t=1;w=1;r[t]=i;e[i]=0;g[i]=1;
			while(t<=w){
				for(j=0;j<f[r[t]].size();j++){
					if(e[f[r[t]][j]]>e[r[t]]+1){
						e[f[r[t]][j]]=e[r[t]]+1;g[f[r[t]][j]]=1;
						if(v[f[r[t]][j]]==0) v[f[r[t]][j]]=1,w++,r[w]=f[r[t]][j];
					}
					else if(e[f[r[t]][j]]==e[r[t]]+1) g[f[r[t]][j]]++;
				}
				t++;v[t]=0;
			}
			for(j=1;j<=n;j++) if(g[j]==2&&e[j]!=9187201950435737471) s++;
		}
		cout<<s<<'\n';
		s=0;
	}
	return 0;
}