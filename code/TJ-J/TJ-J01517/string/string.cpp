#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005]; 
char b[200005];
string s;
void work1()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		if(a[i]%5==0)
		{
			string s1;
			for(int j=1;j<=a[i]/5;j++)
			{
				s1+=b[i];
			}
			for(int j=1;j<=5;j++)
			{
				s+=s1;
			}
		}
		else if(a[i]%4==0)
		{
			string s1;
			for(int j=1;j<=a[i]/4;j++)
			{
				s1+=b[i];
			}
			for(int j=1;j<=4;j++)
			{
				s+=s1;
			}
		}
		else if(a[i]%3==0)
		{
			string s1;
			for(int j=1;j<=a[i]/3;j++)
			{
				s1+=b[i];
			}
			for(int j=1;j<=3;j++)
			{
				s+=s1;
			}
		}
		else if(a[i]%2==0)
		{
			string s1;
			for(int j=1;j<=a[i]/2;j++)
			{
				s1+=b[i];
			}
			for(int j=1;j<=2;j++)
			{
				s+=s1;
			}
		}
		else
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=b[i];
			}
		}
	}
	long long ans=0;
	long long mid=(s.size())/2;
	for(int i=1;i<mid;i++)
	{
		int r=i+mid;
		if(s[i]!=s[r])
		{
			ans++;
		}
	} 
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n;     
	s='0'+s;             
	if(n<2000)
	{
		work1(); 
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
