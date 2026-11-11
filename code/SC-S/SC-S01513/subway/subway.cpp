#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int a[500010],b[500010],c[500010],x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",c,n,m,d,q);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",a[i]);
	}
	cin>>b[1];
	for(int i=2;i<=b[1];i++)
	{
		cin>>b[i];
		i++;
		cin>>c[i];
	}
	for(int i=2;i<=b[1];i++)
	{
		cin>>b[i];
		i++;
		cin>>c[i];
	}
	return 0;
}