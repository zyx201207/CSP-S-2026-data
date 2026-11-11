#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,i1,i2,s1,s2,e1,e2,sum1,sum2;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ll w[m+10]={};
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	cin>>i1;
	ll a1[i1+5]={},t1[i1+5]={};
	for(int i=1;i<=i1;++i)
	{
		cin>>a1[i]>>t1[i];
	}
	cin>>i2;
	ll a2[i2+5]={},t2[i2+5]={};
	for(int i=1;i<=i2;++i)
	{
		cin>>a2[i]>>t2[i];
	}
	cin>>s1>>e1>>s2>>e2;
	sum1=w[s1]+w[e1]+t1[s1]+t1[s1+1]+t2[s1]+t2[s1+1];
	sum2=w[s2]+w[e2]+t1[s2]+t1[e2];
	cout<<sum1<<"\n"<<sum2;
	return 0;
}
