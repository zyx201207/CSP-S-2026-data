#include<bits/stdc++.h>
using namespace std;
const int N=1e9+8;
int n,len,cnt;
char a[N];
int main()
{
	freopen("string.in","r",stdin);
 	freopen("string.out"£¬"w",stdout);
	cin>>n;
	len=0; 
	for(int i=1;i<=n;i++)
	{
		int num;
		char c;
		cin>>num>>c;
		for(int j=1;j<=num;j++)
		{
			a[++len]=c;
		}
	}
	for(int i=1;i<=len/2;i++)
	{
		if(a[i]!=a[len-i+1]) cnt++;
	}
	cout<<cnt;
}
