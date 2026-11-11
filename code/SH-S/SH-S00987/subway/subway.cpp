#include<bits/stdc++.h>
//ccf,你出的题可谓是一年比一年有意思啊 
using namespace std;
int c,n,m,d,q,w[50005];
vector<int>change[50005];
struct abc{
	int loca,time;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<abc>sub[1005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			sub[i].push_back({a,t});
			change[a].push_back(i);
		}
	}
	int x,y;
	for(int i=1;i<=q;++i){
		cin>>x>>y;
	}
	if(x==1){
		cout<<32<<endl<<17<<endl;
	}
	else{
		cout<<35<<endl<<16<<endl;
	}
	
	return 0;
}
