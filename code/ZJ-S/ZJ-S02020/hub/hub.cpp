#include<bits/stdc++.h>
using namespace std;
int c,t,a[500050],f[500050],sumf[500050],n,k;
vector<int> g[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=0;i<500000;i++)
			g[i].clear();
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(sumf,0,sizeof(sumf));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			a[x]++;
			a[y]++;	
		}
		for(int i=1;i<=n;i++){
			f[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			sumf[i]=sumf[i-1]+f[i];
		}
		for(int i=0;i<=n;i++){
			if(n-i*2-sumf[i]<=k){
				cout<<i<<endl;
				break;
			}
		}
	}
}
