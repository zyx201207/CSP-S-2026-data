#include<bits/stdc++.h>
using namespace std;
long long sgj[200001];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	long long n,m,sm=9223372036854775807,ans=0;
	cin>>n>>m;
	for(int a=0;a<n;a++) cin>>sgj[a];
	for(int a=0;a<=n-m;a++)//Æðµã
	{
		sm=9223372036854775807;
		for(int b=a;b<=a+m;b++)sm&=sgj[b];
		ans=max(ans,sm);
	} 
	cout<<ans;
	return 0;
}


