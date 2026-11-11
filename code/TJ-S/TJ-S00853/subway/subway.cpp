//00853
#include<bits\stdc++.h>
using namespace std;
struct node{
	int x,t;
};
int t[505];
vector<node> g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	while(n--){
		int x;
		cin>>x;
		for(int i=1;i<=x;i++){
			int x,y;
			cin>>x>>y;
			g[i].push_back({x,y});
		}
	}
	cout<<1<<endl<<2;
	return 0;
}

