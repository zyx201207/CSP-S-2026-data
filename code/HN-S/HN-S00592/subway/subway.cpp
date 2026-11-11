#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,x,y;
struct node{
	int w,a,t;
}sn[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sn[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>sn[i].a>>sn[i].t;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
	}
	return 0;
} 
