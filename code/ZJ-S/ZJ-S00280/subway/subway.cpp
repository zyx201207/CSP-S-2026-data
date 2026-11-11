#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
const int N=1010;
struct node{
	int a,t;
}a[N][N];
int w[N],k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	bool A=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2) A=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].a>>a[i][j].t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		for(int i=x;i<=y;i++){
			ans+=a[i][k[i]].t;
		}cout<<ans;
	}
	return 0;
}
