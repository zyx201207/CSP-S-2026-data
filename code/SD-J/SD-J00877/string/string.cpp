#include<bits/stdc++.h>
using namespace std;
queue<char> q;
int n,a[250000],o=1,z,g=0;
char c[250000],s[150000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[o]=c[i];
			o++;
		}
	}
	z=(o-1)/2; 
	for(int i=1;i<=z;i++)
	{
	    q.push(s[i]);
	}
	if((o-1)%2==0) z=(o-1)/2+1;
	else z=o/2+1;
	for(int i=o-1;i>=z;i--)
	{
		if(q.front()!=s[i]) g++;
		q.pop();
	}
	cout<<g;
    return 0;
}
