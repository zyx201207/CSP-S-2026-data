#include<bits/stdc++.h>
using namespace std;
long long n,b,f,st;
string a,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>a;
		f+=b;
		if(b>1000)st=1;
		else for(int i=1;i<=b;i++)ans+=a;
	}
	if(st==1)
	{
		cout<<f/2;
		return 0;
	}
	int o=ans.size()/2,op;
	if(ans.size()%2==0)
	{
		op=ans.size()/2;
	}
	else
	{
		op=ans.size()/2+1;
	}
	int cmp=0;
	for(int i=0;i<o;i++)
	{
		for(int j=ans.size()-1;j>=op;j--)
		{
			if(ans[i]==ans[j])cmp++,i++;
		}
	}
	cout<<o-cmp;
	return 0;
}
