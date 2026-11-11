#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b;
	char a;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		cin>>a;
		for(int j=1;j<=b;j++)
		{
			s+=a;
		}
	}
	int ans=s.size();
	int sum=0;
	
	for(int i=0;i<ans/2;i++)
	{
		if(s[i]!=s[n-i])
		{
			
			sum++;
		}
	}
	cout<<sum;
	
	
    return 0;
}
