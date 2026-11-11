#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int  dis[101][101];
int c,n,m,d,a,m1[N],n1[N],a1[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c,n,m,d,a;
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)cin>>m1[N];
	for(int i=1;i<=n;i++){
		for(int i=1;i<=10;i++)cin>>n1[N];
	}
	for(int i=1;i<=a;i++){
		for(int i=1;i<=2;i++)cin>>a1[N];
	}
	if(m1[N]==a1[1]){
		m1[N]=0;
		m1[N]+=m1[N+1];
	}

	for(int k=1;k<=n;k++)
		for(int z=1;z<=n;z++)
			for(int x=1;x<=n;x++)
			if(dis[z][k]+dis[k][x]<dis[z][x])
				dis[z][x]=dis[z][k]+dis[k][x];
cout<<dis[a1[1]][a1[2]]+m1[N];
return 0;
}
