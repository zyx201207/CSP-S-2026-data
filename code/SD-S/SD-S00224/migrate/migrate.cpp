#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[2000005];
map<pair<int,int> ,int> m;
map<pair<int,int> ,int> m1;
int n,d;
int dg(int x,int t){
	int ans=0;
	m1[{x,t}]++;
	if(m1[{x,t}]==2) ans++;
	if(m1[{x,t}]==3) ans--;
	
	for(int i=x+1;i<=n;i++){
		if(s[i]-s[x]>d) break;
		if(m[{i,t+1}]==-1) m[{i,t+1}]=dg(i,t+1);
		ans+=m[{i,t+1}];
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		
		int cnt=0;
		
		for(int i=1;i<=n;i++) cin>>s[i];
		
		cout<<dg(1,0)<<'\n';
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				m[{i,j}]==-1;
				m1[{i,j}]==0;
			}
		}
	}
	return 0;
}
