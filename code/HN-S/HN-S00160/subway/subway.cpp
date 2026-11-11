#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500005];
long long ans=0;
struct Node{
	int zhan,sj;
};
Node subway[505][10];
void fou(int r,int l){
	if(r==l)cout<<ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			
		}
	}
}

int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>subway[i][j].zhan;
		for(int j=1;j<=k;j++) cin>>subway[i][j].sj;
	}
	while (p--){
		int q,w;
		cin>>q>>w;
		fou(q,w);
	}
	return 0;
}
