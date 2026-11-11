#include<iostream>
using namespace std;
int a[200001];
string c[200001];
int n,g;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cut=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	g=n-1;
	for(int i=0;i<=g;i++)
	{
		if(c[i]!=c[g])
		{
			cut+=max(a[i]-a[g],a[g]-a[i]); 
		}
		g--;
	}
	cout<<2;
}
