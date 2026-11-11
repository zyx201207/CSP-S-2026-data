#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	int n,m;
	cin >>n;
	for(int i=1;i<=n;i++)
	{
		cin >>m>>a;
		for(int j=1;j<=m;j++)
		{
			b+=a;	
		} 
	}
	//cout <<b[0]<<b.size();
	long long ans=0;
	for(int i=0;i<(b.size()+1)/2;i++)
	{
		if(b[i]!=b[b.size()-i-1])
		{
			//cout <<i<<endl;
			ans++;
		}
	}
	cout <<ans;
}  
