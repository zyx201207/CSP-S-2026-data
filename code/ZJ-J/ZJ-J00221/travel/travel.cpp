#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2,s3,s4;
ll n1,n2,n3,n4,r1=1;
char c1,c2;
bool pd()
{
	if((c1>='A'&&c1<='C'&&c2>='A'&&c2<='C')||(c1>='D'&&c1<='F'&&c2>='D'&&c2<='F')) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	for(int i=s1.size()-1;i>=0;i--)
	{
		n1+=(s1[i]-'0')*r1;
		r1*=10;
	}
	r1=1;
	for(int i=s3.size()-1;i>=0;i--)
	{
		n3+=(s3[i]-'0')*r1;
		r1*=10;
	}
	c1=s2[s2.size()-1];
	c2=s4[s4.size()-1];
	r1=1;
	for(int i=s2.size()-2;i>=0;i--)
	{
		n2+=(s2[i]-'0')*r1;
		r1*=10;
	}
	r1=1;
	for(int i=s4.size()-2;i>=0;i--)
	{
		n4+=(s4[i]-'0')*r1;
		r1*=10;
	}
	if(n1==n3) cout<<1;
	else cout<<0;
	if(n1==n3&&n2==n4) cout<<1;
	else cout<<0;
	if(n1==n3&&n2==n4&&pd()) cout<<1;
	else cout<<0;
	if(n1==n3&&n2==n4&&pd()&&abs((ll)c1-c2)==1) cout<<1;
	else cout<<0;
	return 0;
}