#include<bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,z;
	cin>>n;
	int m[10000]={0};
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>m[i]>>z;
		for(int j=0;j<m[i];j++)
		{
			s[i]+=z;
		}
	}
	cout<<" "<<s<<" ";
	return 0;
}
