#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001];
struct node{
	int a,b;
};
vector<node> v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,f,c;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>f>>c;
			v.push_back({f,c});
		}
	}
	for(int i=1;i<=m;i++)
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
	}
	return 0; 
}
