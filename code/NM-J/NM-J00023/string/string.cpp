#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,i,j,x=0,y,a1=0,a2=0,a3=0,a4=0,cnt=0,ans=0;
	string s,s2;
	char t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>m>>t;
		for(j=1;j<=m;j++)
		{
			s+=t;
		}
	}
	long long len=s.length(),l=0,r=len-1;
	for(i=0;l!=r;i++)
	{
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
/*

3
2 a
2 b
1 c
*/
