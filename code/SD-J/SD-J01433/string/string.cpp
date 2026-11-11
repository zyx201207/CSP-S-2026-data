#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],cnt;
string c[N],s,x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		while(a[i]--)
		{
			s+=c[i];
		}
	}
	for(int i=-1;i<=n;i++)
	{
		x+=s[n-i];
	}
	for(int i=1;i<=n;i++)
	{
		
		if(s==x)
		{
			cout<<0;
			return 0;
		}
		if(s[i]!=x[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
