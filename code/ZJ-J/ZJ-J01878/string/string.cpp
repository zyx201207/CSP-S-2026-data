#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
long long n,a[200010],t=0,l=0,r,ans=0,x=0,j;
char c[200010];
string s;
cin>>n;
j=0;
for(int i=1;i<=n;i++)
{
	cin>>a[i]>>c[i];
j=a[i]+j;
for(int k=a[i-1];k<j;k++)
{
	s[k]=c[i];
}
}
t=j/2;
r=j-1;

while(t--)
{
	if(s[l]!=s[r])
	{
		s[l]=s[r];
		ans++;
	}
	l++;
	r--;
}
cout<<ans;
		return 0;
}
