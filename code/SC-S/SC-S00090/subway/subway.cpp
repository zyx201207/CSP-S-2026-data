#include<bits/stdc++.h>
using namespace std;
struct sb{
	vector< pair<int,int> >a;
	int zs;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,p,q;
	cin>>c>>n>>m>>p>>q;
	int w[m];
	for(int i=0;i<m;i++)cin>>w[m];
	sb k[n];
	for(int i=0;i<n;i++){
		cin>>k[i].zs;
		for(int j=0;j<k[i].zs;j++){
			pair<int,int>id;
			cin>>id.first>>id.second;
			k[i].a.push_back(id);
		}
	}
	while(q--){
		
		int x,y;cin>>x>>y;
		x--;
		y--;
		int mint=w[x]+w[y];
		cout<<mint;
	}
	return 0;
}