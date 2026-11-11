#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,a[N],t,f,cnt;
string a1,b1;
bool vi(string x)
{
	long long len=x.size();
	for(int i=0;i<len;i++)
	{
		if(x[i]!=x[len-(i+1)])
		{
			f=i;
			return 0;
		}
	}
	return 1;
}
int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>a1;
		for(int j=0;j<=a[i]-1;j++)
		{
			b1+=a1;
		}
	}
	long long len=b1.size();
	if(vi(b1)==1)
	{
		cout<<0;
	}
	else
	{
		while(vi(b1)!=1)
		{
			b1[len-(f+1)]=b1[f];
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}