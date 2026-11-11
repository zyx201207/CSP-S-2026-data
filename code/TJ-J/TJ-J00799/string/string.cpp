#include <bits/stdc++.h> 
using namespace std;
long long n;
long long xun=0;
char fi[1000005];
char la[1000005];
long long di=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long  a;
		char c;
		cin>>a>>c;
		for(int j=xun;j<(xun+a);j++)
		{
			fi[j]=c;
		}
		xun+=a;
	}
	for(int i=0;i<xun;i++) 
	{
		la[i]=fi[(xun-i-1)];
	}
	for(int i=0;i<xun;i++) 
	{
		if(la[i]!=fi[i])
		di++;
	}
	cout<<(di+2-1)/2;
	return 0;
}
