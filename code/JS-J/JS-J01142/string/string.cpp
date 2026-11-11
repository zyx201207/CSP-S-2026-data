#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100005];char c[100005];
	bool x=1;
	long long al=0;
	string s=" ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=1)
		{
			x=0;
		}
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		al+=a[i];
	}
	if(x)
	{
		cout<<1;
		return 0;
	}
	long long L=1,R=al,cnt=0;
	while(L<=R)
	{
		if(s[L]!=s[R])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
