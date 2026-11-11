#include<bits/stdc++.h>
#define ll long long
using namespace std;
string S;
char a;
ll N,n,num,xb=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>n>>a;
		for(int j=xb;j<=xb+n;j++)
		{
			S[j]=a;
		}
		xb+=n;
	}
	for(int i=1;i<=xb/2;i++)
	{
		if(S[i]!=S[xb+1-i])
		{
			num++;
			S[xb+1-i]=S[i];
		}
	}
	cout<<num;
	return 0;
}
