#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,num[500005];
struct node{
	int cnt,quan;
}
vector<node> tu[500005];
vector<int> zhuan[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			int x,y;
			cin>>x>>y;
			tu[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<tu[i].size();j++){
			
		}
	}
	return 0;
}