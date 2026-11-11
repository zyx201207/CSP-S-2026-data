#include<bits/stdc++.h>
using namespace std;
long long a[2000000];
int main()
{
	int n,m;
	cin>>n>>m;
	int maxn=0;
	int p1=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x>maxn)
		{
			maxn=x;
			x=a[i]; 
		}
		if(i==0)
		{
			p1=x;
		}
	} 
	for(int i=0;i<=m;i++)
	{
		if(m==1)
		{
			cout<<p1;
		}
		int r=m;//Ð´²»ÍêÁË£¬°Ý°Ý 
	}
	return 0;
}
