#include<bits/stdc++.h>
using namespace std;
struct abab
{
	int gs;
	char s;
}baba[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long L=0,i,j,ans=0;
	string s;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>baba[i].gs>>baba[i].s;
		L+=baba[i].gs;
		for(j=1;j<=baba[i].gs;j++)
		s+=baba[i].s;
	}
	for(i=0,j=L-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
