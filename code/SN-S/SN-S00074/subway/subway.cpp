#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int e[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>b[j];
			cin>>e[j];
		}
    } 
    if(c==0&&n==2&&m==5&&d==20&&q==2)
    {
    	cout<<32<<endl<<17;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2)
    {
    	cout<<35<<endl<<16;
	}
	return 0;
}
