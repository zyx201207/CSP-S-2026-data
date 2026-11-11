#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a,s[N],x[N];
int n,m[N],y[N];
long long k,b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>a;
		s[i]=a;
		m[i]=b;
	}
	int i=1,j=n;
	while(i<j)
	{
		if(s[i]==s[j])
		{
			if(m[i]>m[j])
			{
				j--;
				m[i]-=m[j];
			}
			else if(m[i]<m[j])
			{
				i++;
				m[j]-=m[i];
			}
			else
			{
				i++;
				j--;
			}
		}
		else
		{
			if(m[i]>m[j])
			{
				k=k+m[j];
				m[i]-=m[j];
				j--;
				
			}
			else if(m[i]<m[j])
			{
				k=k+m[i];
				m[j]-=m[i];
				i++;
				
			}
			else
			{
				k=k+m[i];
				i++;
				j--;
			}
		}
	}
	
	cout<<k;
	return 0;
}