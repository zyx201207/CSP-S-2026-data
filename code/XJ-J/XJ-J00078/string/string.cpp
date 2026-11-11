#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c;
	char a;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>c>>a;
		for(int i = 1;i <= c;i++) s+=a;
	}
	int len=s.size();
	long long sum=0;
	if(len%2==1)
	{
		int mid=len/2;
		for(int i = 1;i <= mid;i++)if(s[i]!=s[n-i])sum++;
	}
	cout<<sum;
	return 0;
}


