#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;

int n;
int a[maxn];
char c[maxn];
int b[maxn];
//int sum=0;
//int ans=0;
//
//bool str()
//{
//	bool flag=0;
//	for(int i=1,j=n;i<=j;i++,j--)
//	{
//		if(c[i]!=c[j]) flag=1,b[++sum]=i;
//		else if(a[i]!=a[j]&&i+1!=j) flag=1,b[++sum]=i;
//	}
//	if(flag) return false;
//	return true;
//}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
//	cin>>n;
//	int len=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i]>>c[i];
//		len+=a[i];
//	}
//	if(str()) cout<<0;
//	int cnt=0;
//	for(int i=1;i<=sum;i++)
//	{
//		if(c[b[i]]==c[n-b[i]+1])
//		{
//			int x=abs(a[b[i]]-a[n-b[i]+1]);
//			if(a[b[i]]>a[n-b[i]+1])
//			{
//				if(cnt==0) cnt=x,ans+=x;
//				else if(cnt>=x)
//				{
//					cnt-=x;
//				}
//				else
//				{
//					ans+=x-cnt;
//					cnt=x-cnt;
//				}
//			}
//			else
//			{
//				if(cnt==0) cnt=x,ans+=x;
//				else if(cnt>=x)
//				{
//					cnt-=x;
//					a[b[i]]=a[n-b[i]+1];
//				}
//				else
//				{
//					ans+=x-cnt;
//					cnt=x-cnt;
//				}
//			}
//		}
//		else
//		{
//			int x=abs(a[b[i]]-a[n-b[i]+1]);
//			if(a[b[i]]>a[n-b[i]+1])
//			{
//				if(cnt==0) cnt=x,ans+=a[b[i]];
//				else if(cnt>=x)
//				{
//					cnt-=x;
//				}
//				else
//				{
//					ans+=x-cnt;
//					cnt=x-cnt;
//				}
//			}
//			else if(a[b[i]]<a[n-b[i]+1])
//			{
//				if(cnt==0) cnt=x,ans+=x;
//				else if(cnt>=x)
//				{
//					cnt-=x;
//				}
//				else
//				{
//					ans+=x-cnt;
//					cnt=x-cnt;
//				}
//			}
//			else ans+=a[b[i]];
//		}
//	}
//	cout<<ans+cnt;

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b[i]+=a[i-1];
	}
	int ans=0;
	for(int i=1,j=n;i<=j;i++,j--)
	{
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		if(i+1==j&&c[i]==c[j]) continue ;
		if(a[i]>a[j])
		{
			ans+=abs(a[i]-a[j]);
			if(a[i+1]>a[j-1])
			{
				a[j-1]+=abs(a[i]-a[j]);
			}
			else if(a[j-1]>a[j+1])
			{
				a[i+1]+=abs(a[i]-a[j]);
			}
			else
			{
				a[i+1]-=abs(a[i]-a[j])/2;
				a[j-1]-=abs(a[i]-a[j])/2;
				if(abs(a[i]-a[j])%2==1)
				{
					a[i+1]-=1;
				}
			}
		}
		else if(a[i]<a[j])
		{
			ans+=abs(a[i]-a[j]);
			if(a[i+1]>a[j-1])
			{
				a[j-1]+=abs(a[i]-a[j]);
			}
			else if(a[j-1]>a[j+1])
			{
				a[i+1]+=abs(a[i]-a[j]);
			}
			else
			{
				a[i+1]-=abs(a[i]-a[j])/2;
				a[j-1]-=abs(a[i]-a[j])/2;
				if(abs(a[i]-a[j])%2==1)
				{
					a[i+1]-=1;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}

