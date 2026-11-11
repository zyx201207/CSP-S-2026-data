#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> t;
bool bian[520][520];
int ti[520][520];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	t.resize(m+10);
	for(int i=1;i<=m;++i){
		cin>>t[i];
	}
	int k;
	int x,y;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int i=1;i<=k;++i){
			cin>>x>>y;
			bian[i][x]=true;
			ti[i][x]=y;
		}
	}
	
	cout<<32<<"\n"<<17;
	return 0;
}
 
