#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("strint.out","w",stdout);
	int n = 0,a = 0;
	char ch = 0;
	string s1 = "";
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>a>>ch;
		for(int j = 0;j < a;j++)
			s1 += ch;
	}
	string s2 = s1;
	reverse(s1.begin(),s1.end());
	int cnt = 0;
	for(int i = 0;i < s1.size() / 2;i++)
	{
		if(s1[i] != s2[i])
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
