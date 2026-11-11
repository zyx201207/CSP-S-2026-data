#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node
{
	int num;
	char c;
};
Node s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		s[i].num=x;s[i].c=c;
	}
	long long l=1,r=n,ans=0;
	while(l<=r)
	{
		if(s[l].num>s[r].num)
		{
			if(s[l].c!=s[r].c) ans=ans+s[r].num;
			s[l].num-=s[r].num;
			r--;
		}
		else
		{
			if(s[l].c!=s[r].c) ans=ans+s[l].num;
			s[r].num-=s[l].num;
			l++;
			if(s[r].num==0) r--;
		}
		
	}
	cout<<ans;
	return 0;
}