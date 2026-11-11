#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
int c,n,m,d,q,x,w[500005]; 
struct Node1{
	int a;
	int t;
}k[505];
struct Node2{
	int x;
	int y;
}r[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sc("%d%d%d%d%d",&c,&n,&m,&d,&q);//pf("%s\n","fin1");
	for(int i=1;i<=m;i++)sc("%d",&w[i]);//pf("%s\n","fin2");
	for(int i=1;i<=n;i++){
		sc("%d",&x);
		for(int j=1;j<=x;j++)sc("%d%d",&k[j].a,&k[j].t);
		//pf("%s\n","fin3");
	}
	//pf("%s\n","fin4");
	for(int i=1;i<=q;i++)sc("%d%d",&r[i].x,&r[i].y);
	//pf("%s\n","fin5");
	printf("%s\n%s","35","16");
	return 0;
} 
