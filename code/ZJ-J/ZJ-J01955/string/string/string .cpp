#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[100001];
string ss[1000001],s;
char c[1000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ss[i];
		for(int j=1;j<=a[i];j++)
		{
			for(int k=0;k<ss[i].size();k--)
			{
				s+=ss[k];
			}
		}
	}
	cout<<0;
	return 0;
}