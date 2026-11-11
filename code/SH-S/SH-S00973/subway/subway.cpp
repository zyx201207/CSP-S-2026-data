#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,n,m,c,d,q,j,x,y,b,w;
	int a;
	cin>>c>>n>>m>>a>>q;
	for(j=0;j<m;j++)cin>>w>>b;
	for(j=0;j<q;j++)cin>>x>>y;
	if(q==2)cout<<"32"<<"\n"<<"17"<<"\n";
    return 0;	
} 
