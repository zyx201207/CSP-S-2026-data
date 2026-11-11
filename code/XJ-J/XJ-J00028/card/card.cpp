#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m,a[N],to[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> g;
	for(int l=1;l<=n;l++){
		g.clear();
		for(int r=l;r<=n;r++){
			int x=a[r];
			bool f=false;
			for(int j=0;j<g.size();j++){
				if(g[j]==x){
					f=true;
					break;
				}
			}
			if(f){
				while(!g.empty() && g.back()!=x) g.pop_back();
			}else g.push_back(x);

			
		}
		for(int j=0;j<g.size();j++){
			to[g[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++) cout<<to[i]<<" ";
	return 0;
}
