#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a1;
		cin>>a1;
		char c1;
		cin>>c1;
		for(int j=1;j<=a1;j++)
		{
			s+=c1;
		}
    }
    cout<<s<<endl;
    return 0;
}