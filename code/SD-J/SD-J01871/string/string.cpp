#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int l[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		l[i]=a;
		s+=b;
	}
	long long ans=0;
	int i=1,j=n;
	while(i<j)
	{
		int temp=min(l[i],l[j]);
		if(s[i-1]!=s[j-1])ans+=temp;
		l[i]-=temp;
		l[j]-=temp;
		if(l[i]==0)i++;
		if(l[j]==0)j--;
	}
	cout<<ans;
	return 0;
}
