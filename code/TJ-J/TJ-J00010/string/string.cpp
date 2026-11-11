#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=1;
	long long cishu=0; //修改次数 
	cin>>n;  //输入字符串段数
	int a[n+5];
	char c[n+5],S[1000000];

	if(n==1)
	{
		cout<<cishu;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			S[k]=c[i];
			k++;
		}
	}
	
	
	cout<<cishu;
	return 0;
 } 
