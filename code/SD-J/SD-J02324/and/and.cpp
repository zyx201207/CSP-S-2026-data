#include<bits/stdc++.h>
using namespace std;
int a[200001][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,j,maxx,z,l,s=1;
	bool f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i][0];
	for(int i=1;i<=n;i++)
	{
		j=1;
		x=a[i][0];
		z=0;
		while(1){
			a[i][j]=x%2;
			x=x/2;
			z++;
			j++;
			if(x==0)break;
		}
		if(z>maxx)maxx=z;
	}
	
	for(int i=maxx;i>=1;i--)
	{
		l=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1)l++;
			if(l==m)
			{
				f=1;
				break;
			}
		}
		if(f==1){
			for(int k=1;k<=i;k++)
				s=s*2;
			cout<<s-1;
			break;
		}
	}
	return 0;
}
