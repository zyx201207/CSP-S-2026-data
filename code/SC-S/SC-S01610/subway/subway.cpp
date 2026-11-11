#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int N=2e4+5;
int n,m,q;
int c,d;//useless
int w[N];
int a[505][N],t[505][N];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(unsigned int i=1;i<=m;i++)
		cin>>w[i];
	for(unsigned int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}//qwq