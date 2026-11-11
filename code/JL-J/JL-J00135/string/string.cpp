#include <bits/stdc++.h>
using namespace std;
long long length=0,total=0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char t;
		long long temp;
		cin>>temp>>t;
		for(int j=0;j<temp;j++)
			s+=t;
		length+=temp;
	}
	for(int i=0;i<length/2;i++)
	{
		if(s[i]!=s[length-i-1])
			total++;
	}
	cout<<total<<endl;
	
	return 0;
}
