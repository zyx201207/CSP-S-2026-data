#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	char b[N];
	cin>>n;
	while(n--)
	{
		int m;
		char a;
		cin>>m>>a;
		for(int i=sum;i<sum+m;i++) b[i]=a;
		sum+=m;
	}
	int ans=0;
	for(int i=0;i<sum/2;i++)
	{
		if(b[i]!=b[sum-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
