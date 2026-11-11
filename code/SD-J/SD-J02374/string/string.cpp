#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string ans="";
	long long a,n,sumlen=0,sum=0;
	char l;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>n>>l;
		for(int j=1;j<=n;j++)ans+=l;
		sumlen+=n;
	}
	//cout<<sumlen/2;
	for(int i=0;i<sumlen/2;i++)
	{
		cout<<ans[i]<<" "<<ans[sumlen-i-1]<<endl;
		if(ans[i]!=ans[sumlen-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
 } 
