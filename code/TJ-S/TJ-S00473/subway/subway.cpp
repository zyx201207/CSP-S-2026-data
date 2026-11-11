#include<bits/stdc++.h>
using namespace std;
int c,line,station,dmax,q,l,num;
struct under{
	int u,v,time;
}a[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>line>>station>>dmax>>q;
	for(int j=0;j<line;j++){		
		for(int i=0;i<station;i++){
			scanf("%d%d",&num,&l);
			a[num].time=l;
			a[num].u=j,a[num].v=i;
		}
	}
	for(int i=0;i<q;i++){
		cin>>u>>v;
		cout<<a[u]+a[v]<<endl;
	}
	return 0;
}

