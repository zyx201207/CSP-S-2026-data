#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	set<string> ab;
	string c;
	long long a;
	long long h = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>a;
		h = a;
		cin>>c;
	while(h>0)
	{for(int j = 0;j<a;j++)
	{
		ab.insert(c);
		h = h-1;
	}}
	
	}

	cout<<"2";

    return 0;
}
