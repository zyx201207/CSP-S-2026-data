#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char zf;
}a[400155];
long long n,ans,oh=0;
void pt(long long nn,long long bs)
{
	cout<<endl;
	for(int i=bs+1;i<=nn;i++)
	{
		cout<<a[i].zf<<" "<<a[i].num<<endl;
	}
	cout<<endl;
}
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long n1=n;
	for(int i=1;i<=n1;i++)
	{
		cin>>a[i].num>>a[i].zf;
		if(a[i].zf==a[i-1].zf)
		{
			a[i-1].num=a[i-1].num+a[i].num;
			i--;
			n1--;
		}
	}
	long long n2=n1;
	for(int i=1;i<=n1;)
	{
		long long len1=a[i].num,len2=a[n1-i+1+oh].num;
		char d=a[i].zf,b=a[n1-i+1+oh].zf;
		if(len1==-1)continue;
		if(d!=b)
		{
			if(len1>len2)
			{
				ans+=a[n1-i+1+oh].num;
				a[i].num-=a[n1-i+1+oh].num;
				n1--;
			}
			else if(len1==len2)
			{
				ans+=len1;
				a[i].zf=a[n1-i+1+oh].zf;
				i++;
				oh++;
				n1--;
//				cout<<a[n-i+1+oh].zf;
			}
			else if(len2>len1)
			{
//				cout<<"bushi;";
				ans+=a[i].num;
				a[n1-i+1+oh].num-=a[i].num;
				oh++;
				i++;
			}
		}
		else 
		{
			if(a[n1-i+1+oh].num==a[i].num)
			{
				i++;
				n1--;
				oh++;
			}
			else if(a[n1-i+1+oh].num>a[i].num)
			{
				a[n1-i+1+oh].num-=a[i].num;
				i++;
				oh++;
			}
			else
			{
				a[i].num-=a[n1-i+1+oh].num;
				n1--;
			}
		}
//		cout<<endl;
//		cout<<"test:"<<n1-i+1+oh<<" "<<i<<" "<<n1<<endl;
//		cout<<"ans:"<<ans;
//		pt(n1,oh);
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}
