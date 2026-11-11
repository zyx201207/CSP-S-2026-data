#include<bits/stdc++.h>
using namespace std;
long long n,len=0,cnt=0,sum=0;
int a[100000001];
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	if(len==1)
	{
		cout<<0;
		return 0;
	}
	else if(len==2)
	{
		cout<<1;
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		if(s[i]==s[len-1])
		{
			cnt++;
		}
	}
	if(cnt==len)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[len-i])
		{
			sum++;
			s[len-i]=s[i];
		}
	}
	cout<<sum;
	return 0;
}
