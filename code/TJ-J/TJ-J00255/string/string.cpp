#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;        
	string str="";
	for(int i=0;i<n;i++)
	{
		int num;
		char c;
		cin>>num>>c;
		for(int j=0;j<num;j++)str+=c;
	}
	string s=str;
	reverse(str.begin(),str.end());
	if(s!=str)
	{
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=str[i])sum++;
		}
	}
	cout<<sum;
	return 0;
}

