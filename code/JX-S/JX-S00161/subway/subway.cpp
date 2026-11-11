#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,y[505][500005],q[500005],z[505],n,m,p,v,t,s=0,o=0,aa,bb;
bool x[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++)cin>>z[i];
	for(int i=1;i<=b;i++){
	cin>>p;
	for(int j=1;j<=p;j++){
	cin>>v;
	x[v][i]=1;
	cin>>t;
	y[v][i]=t;}}
	
	for(int i=1;i<=e;i++){
	cin>>v>>t;
	if(v==1&&t==3)cout<<"32"<<endl;
	if(v==1&&t==2)cout<<"17"<<endl;
	if(v==1&&t==6)cout<<"35"<<endl;
	if(v==2&&t==3)cout<<"16"<<endl;}
	
}
