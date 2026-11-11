#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N],n,m,c=1,s1;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int T;
		char b;
		cin>>T>>b;
		for(int i=1;i<=T;i++)s+=b;
	}
	int len =s.size();
	for(int i=1;i<=(len+1)/2;i++)
	{
		if(s[i]!=s[len+1-i])s1++;
	}
	cout<<s1;
	return 0;
}
