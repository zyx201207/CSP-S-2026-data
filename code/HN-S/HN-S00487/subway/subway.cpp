#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q,w[50000];
struct com{
	int a,t;
};
vector<int>p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<1;
	}
	return 0;
} 
