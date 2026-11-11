#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2010100];
int main(){
 freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	int c,d=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
			c=a[i];
		else
			c&=a[i];
			d=max(d,a[i]);
	}
	if(m==n)
		cout<< c;
	else if(m==1)
		cout<<d;
	else if(m==2&&n<=10000)
	{
		int g=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				g=max(g,a[i]&a[j]);
			}
		cout<<g;
	}else if(m==3&&n<=3000){
		int g=-1;
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
			{
				if(i==j||j==k||i==k) continue;
				g=max(g,a[i]&a[j]&a[k]);
			}
	}else if(m==n-1){
		for(int i=1;i<=n;i++)
		{
			if(i==1)
				c=c^a[1];
			else c=max(c,c^a[i]);
		}
	}
	else	cout<<d;
	return 0;
} 
