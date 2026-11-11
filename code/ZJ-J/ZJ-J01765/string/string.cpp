#include<bits/stdc++.h>
using namespace std;
long long x,n,ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string ss="";
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(int i=1;i<=x;i++)
		{
			ss=ss+c;
		}
	}
	int i1=0,j1=ss.size()-1;
	while(i1<j1)
	{
		if(ss[i1]!=ss[j1])ans++;
		i1++;
		j1--;
	}
	cout<<ans;
	return 0;
}
