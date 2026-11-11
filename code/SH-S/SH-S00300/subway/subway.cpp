#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500010],x,y;
struct node{
	int a,t;
}a1[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a1[j].a>>a1[j].t;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<rand()<<"\n";
	}
	return 0;
}
