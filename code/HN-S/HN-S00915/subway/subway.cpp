#include<bits/stdc++.h>
using namespace std;
struct lin{
	int a=-1,t=-1;
}a[500][500000];
struct numbe{
	int x,y;
}b[100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,j,T=0;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n];
	for(i=0;i<m;i++)
	cin>>w[i];
	for(i=0;i<n;i++){
		cin>>k[i];
		for(j=0;j<k[i];j++)
			cin>>a[i][j].a>>a[i][j].t; 
	}
	for(i=0;i<q;i++){
	cin>>b[i].x>>b[i].y;
	int g;
	cout<<w[b[i].x-1]+w[b[i].y+1]+(b[i].y-b[i].x)*a[0][0].t<<endl;
	}
	return 0;
}
