#include<bits/stdc++.h>
using namespace std;
int b[1000005];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		vector<int>a[86626];
		memset(b,0,sizeof(b));
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			b[u]++;
			b[v]++;
		}
		int cnt=0,ans=0;
		while(cnt+k<n){
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					cnt++;
					b[i]--;
				}
			}
			for(int i=1;i<=n;i++){
				if(b[i]==0){
					b[i]--;
					for(int j=0;j<a[i].size();j++){
						b[a[i][j]]--;
					}
				}
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
