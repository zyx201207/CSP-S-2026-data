#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
int a;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
}