#include<bits/stdc++.h>
using namespace std;
//struct xxc
//{
//	long long da;
//	long long xiao;
//	char zifu;
//}xxc[200100];
string s;
int a[200100];
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
//	long long sum=0;
//	for(int i=1;i<=n;i++)
//	{
//		long long p;
//		cin>>p>>xxc[i].zifu;
//		sum+=p;
//		xxc[i].da=sum;
//		xxc[i].xiao=xxc[i-1].da+1;
//	}
//	int j=n;
//	bool f=0;
//	long long e,k,h=sum,b,res=0;
//	for(int i=1;;i++)
//	{
//		e=xxc[i].xiao;
//		k=xxc[i].da;
//		if(k>sum/2)
//		{
//			k=sum/2;
//			f=1;
//		}
//		for(int p=j;;p--)
//		{
//			j=p;
//			b=sum+1-k;
//			if(xxc[p].xiao<b)
//			{
//				if(xxc[p].zifu!=xxc[i].zifu)
//				{
//					res+=(k-e+1);
//					h-=(k-e+1);
//					cout<<res<<' ';
//					break;
//				}
//			}
//			else
//			{
//				if(xxc[p].zifu!=xxc[i].zifu)		
//				{
//					res+=(h-b+1);
//				cout<<res<<' ';
//					e+=(h-b+1); 
//				}
//			}
//		}
//		if(f==1)
//			break;	
//	}
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
			s+=c; 
	}
	long long k=s.size();
	for(int i=0;i<k/2;i++)
	{
		if(s[i]!=s[k-i-1])	
			res++;
	}
	cout<<res;
}
