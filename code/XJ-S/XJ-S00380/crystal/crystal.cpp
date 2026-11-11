#include<bits/stdc++.h>
using namespace std;
int n;
long long m;//=0;
string s;
long long a[166666];
long long c[166666];
long long sum=0;
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
    //if(a[1]<0)
//    string ss;
//    for(int i=s.size()-1;i>=0;i--)
//    {
//    	ss+=s[i];
//	}
//	for(int i=2;i<=1;i++)
//	{
//		cout<<"ssss";
//		return 0;
//	}
//    for(int i=0;i<=ss.size()-1;i++)
//    {
//    	int l=1;
//    	for(int j=2;j<=i+1;j++)
//    	{
//    		l*=10;
//		}
//    	m+=(ss[i]-'0')*l;
//}
//cout<<"1";//<<"   "<<m;
//return 0;
	for(int i=1;i<=n-1;i++)
	{
		c[i]=a[i+1]-a[i];
	}
	
	for(int i=1;i<=n-1;i++)
	{
		sum+=c[i]*i;
		if(sum>m)
		{
		//	cout<<"1";
			break;
		}
		else if(i==n-1)
		{
			cout<<n;
			return 0;
		}
	}//	cout<<"2";
    sum=0;
	for(int i=1;i<=n-1;i++)
	{
		int ans1=0;
		sum=0;
		int flag=0; 
		for(int j=i;j<=n-1;j++)
		{
			sum+=c[j]*j-i+1;
			if(sum>m)
			{
				break; 
			} 
			ans1++;
			if(j==n-1)
			{
				flag=1;
			}
		}
		if(ans1>ans)
		{
			ans=ans1;
			if(flag==1)
			{
				cout<<ans+1;
				//cout<<"o";
				return 0;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
