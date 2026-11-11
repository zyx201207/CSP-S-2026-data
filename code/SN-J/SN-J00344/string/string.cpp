#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	string s1,s2,s3;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>s1;
		while(a!=0)
		{
			s=s+s1;
			a--;
		}
		
	}
	int len=s.size();
for(long long i=1;i<=len;i++)
{
	if(s[i]==s[i]-1&&s[i]==s[i+1])
	{
		cout<<"0";
	}
}

int cnt1=0;
int cnt2=0;
	while(true)
	{long long i=1;

	long long r=n;
	long long p=(i+r)/2;
	
	
		if(s[i]==s[n])
		{
			i++;
			n--;
		}
		else
		{
			s[n]=s[i];
			cnt1++;
		}
		if(i+1>=n)
		{
			break;
		}
	}
	cout<<cnt1;
	
 } 
