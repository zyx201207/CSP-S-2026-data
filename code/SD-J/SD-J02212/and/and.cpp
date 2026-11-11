#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d[200001],maxm=-1; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
		cin>>d[i];
	sort(d+1,d+a+1);
	for(int i=1;i<a-b;i++)
	{
		c=d[a-i+1];
		for(int j=a-i+1;j>a-b-i+1;j--)
			c=c&d[j];
		if(c!=0)
		{
			if(maxm<c)
				maxm=c;
			else
				break;
		}
	}
	cout<<maxm;
	return 0;
} //AC
