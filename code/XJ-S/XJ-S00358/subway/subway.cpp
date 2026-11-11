#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,k,l,tx,ty,dx,dy,bx,by,w[1000005],a[1005][1005],t[1005][1005],ans,flag,flag1;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,i1,j1,i2,j2,hh;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	cin>>w[i];
	l=1;
	for(i=1;i<=n;i++)
	{
	cin>>k;	
	for(i=1;i<=k;i++)	
	cin>>a[l][i]>>t[l][i];
	l++;	
	}
	for(hh=1;hh<=q;hh++)
	{
	flag=0;flag1=0;
	ans=w[tx];
	cin>>tx>>ty;	
	for(i=1;i<=l;i++)
	{
	for(j=1;j<=2;j++)	
	if(a[i][j]==tx)	
	{
	flag=1;
	break;	
	}	
	if(flag==1)
	break;
	}
	ans+=t[i][j];
	ans+=t[i][3-j];
	i1=1;j1=j;
	while(1)
	{
	for(i2=1;i2<=l;i2++)
	for(j2=1;j2<=2;j2++)
	if(a[i2][j2]==a[i1][3-j1]&&i2!=i1)
	{
	ans=ans+t[i1][3-j1]+t[i2][j2];	
	i1=i2;j1=j2;		
	}	
	if(a[i1][3-j1]==ty)
	{
	ans=ans+t[i1][3-j1]+w[ty];
	break;	
	}		
	}
	cout<<ans<<endl;			
	}
	return 0;
}
