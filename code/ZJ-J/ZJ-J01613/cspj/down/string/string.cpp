#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char>v={};
	int n;
	cin>>n;
	long long z;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>z>>c;
		
	}
	z=0;
	for(long long i=0;i<=v.size()/2;i++)
	{
		//cout<<i<<' '<<z<<endl;
		if(v[i]!=v[v.size()-1-i])
	  {
		  z++;
	  }
	}
	cout<<z;
	return 0;
}
