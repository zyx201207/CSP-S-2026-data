#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010],n,ans,m,c[31];
vector<int> g[34];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=a[i],j=0;
		while(b){
			if(b%2==1){
				g[j].push_back(i);
			}
			b/=2;
			j++;
		}
	}
	for(int i=32;i>=0;i--){
		if(g[i].size()>=m){
			if(i==0){
				cout<<ans+1;
				return 0;
			}
			for(int j=i-1;j>=0;j--){
				g[j].clear();
			}
			for(int j=0;j<g[i].size();j++){
				int b=a[g[i][j]],v=0;
				while(b){
					if(b%2==1){
						g[v].push_back(g[i][j]);
					}
		     		b/=2;
			   	    v++;
			   	    if(v==i) break;
		        }
			}
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
