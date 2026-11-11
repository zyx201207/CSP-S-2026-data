#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    long long a[500001];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<n;i++)
	{//起始水晶 
		long long m1=m;//m1为剩余操作次数 
		for(int j=i;j<=n;j++)
		{//结尾水晶 
			long long b=a[j]-a[j-1];
			if(m1-(b*(j-i))>=0)
			{
				m1-(b*(j-i));//使水晶能量值相等  
				if(sum<j-i+1)sum=j-i+1;
			}
		}
	}
	cout<<sum;
    return 0;
}
