#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int a[N];
char c[N];
int s1[N],s2[30];
int f,rp;
unsigned long long s[N];
int ans;
void ma(int i,int j)
{
	int x=max(i,j);
	s1[x]-=1;
	ans+=s1[i];
}
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int idx=1;
	for(int i=2;i<=n;i++)
	{
		if(c[i]==c[i-1])
		{
			s1[idx]+=a[i];
			s2[idx]=c[i];		
		}
		else
		{
			s1[++idx]+=a[i];
			s2[++idx]=c[i];
		}
		if(s1[idx]==1)f++;
		if(c[i]!=c[1])rp++;
	}
	s[1]=s1[1];
	for(int i=2;i<=idx;i++)
	{
		s[i]=s[i-1]+s1[i];
	}
	int cnt=0;
	if(n==1)cout<<0;
	else if(n==2)
	{
		if(c[1]==c[2])cout<<0;
		else if(a[1]==a[2])cout<<(a[1]+a[2])/2;
		else
		{
			cout<<min(a[1],a[2]); 
		}
	}
	else if(idx==3)cout<<s[idx-1];
	else if(f==idx-1)
	{	
		if(n%2==0)cout<<n/2;
		else cout<<((n-1)/2);
	}
	else if(rp==0)cout<<0; 
	else if(n==3)cout<<2;
	else
	{
		int i=(idx+1)/2-1,j=(idx+1)/2+1;
		if(s[i+1]>s[idx]-s[j-1])cout<<s[idx]-s[j-1];
		else
		{
			while(i!=1&&j!=idx)
			{
//				if(s[i]%2==1)
//				{
//					if(s1[(idx+1)/2]%2==0)
//					{
						ans+=s1[(idx+1)/2];
						cnt=s[idx]-s1[(idx+1)/2]-1;
						ma(i,j); 
//					}
//				}
				i--,j++;
			}
			cout<<ans;
		}
		
	}
	return 0;
}
