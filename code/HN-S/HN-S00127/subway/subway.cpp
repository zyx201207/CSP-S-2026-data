#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long s,v;
};
long long c,n,m,d,q;
long long a[5000010];
Node b[5000010];
vector<Node>g[5000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
    	cout<<a[i];
	}
	for(int i=1;i<=m;i++){
    	long long t;
    	cin>>t;
    	for(int j=1;j<=t;j++){
    		cin>>b[j].s>>b[j].v;
		}
		for(int j=1;j<=t;j++){
    		for(int o=1;o<=t;o++){
    			if(j!=o){
    				g[b[j].s].push_back({b[j].v+b[o].v,b[o].s});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=g[i].begin();j!=g[i].end().s;++j){
			
		}
	}
	return 0;
} 
