#include<bits/stdc++.h>
using namespace std;
int n,a;
long long sum,num;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	s+='0';
	for(int i=1;i<=n;i++)
	{
		cin >> a >> c;
		sum+=a;
		for(int j=1;j<=a;j++) s+=c;
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i+1]) num++;
	}
	cout << num;
	return 0;
}
