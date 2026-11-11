#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int c,T,n,k,d[10010];vector<int>t[10010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)t[i].clear(),d[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			t[x].push_back(y);
			t[y].push_back(x);
			d[x]++,d[y]++;
		}
		if(n<=k){
			cout<<"0\n";continue;
		}int sum=0;
		for(int i=1;i<=n;i++)
			if(d[i]==1)sum++;
		if(k>=n-sum-1){
			cout<<"1\n";continue;
		}
		cout<<"2\n";
	}
	return 0;
}
