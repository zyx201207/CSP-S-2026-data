#include<bits/stdc++.h>
using namespace std;
long long a,n,js=0;
string b={},d,y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a>>d;
		for(int s=1;s<=a;s++)
		{
			b=b+d;
		}
	}
	y=b;
	int l=b.size();	
	for(int i=0;i<l/2;i++)
	{
		swap(b[i],b[l-i-1]);
		if(b[i]!=y[i])js++;
	}
	cout<<js;
	return 0;
}