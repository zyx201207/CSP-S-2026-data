#include <bits/stdc++.h>
using namespace std;
string c1,c2,c,z;
int a,b,x,y,a[3]={1,1,1,1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>b>>c>>c2>>x>>y>>z;
	if(c1!=c2) a[0]=0;
	if(a!=x||b!=y) a[1]=0;
	if(((c>='A'&&c<="C")&&(z=='D'||z=='F'))||((c=='D'||c=='F')&&(z>='A'&&z<="C"))) a[2]=0;
	if((int)abs(c-z)!=1) a[3]=0;
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
