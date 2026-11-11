#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
struct node {
	int l;
	char c;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	long long sum_l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].c;
		sum_l+=a[i].l;
	}
	if(sum_l<=1e8)
	{
		string s="";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].l;j++) s+=a[i].c;
		 }
		
		string s_=s; 
		reverse(s.begin(),s.end());
		long long cnt=0;
		for(int i=(sum_l+1)/2;i<sum_l;i++) if(s[i]!=s_[i])cnt++;
		cout<<cnt;
		return 0; 
	}
	long long change=0;
	long j=0;
	long long mid=(sum_l+1)/2;
	long long now=0;
	for(int i=1;i<=n;i++)
	{	
		now+=a[i].l;
		if(now>=mid)
		{
			now-=a[i].l;
			j=i;
			break;
		}
	}
	for(int i=1;i<j+1;i++)
	{
		if(a[i].c!=a[j+i].c)
		change+=a[i].l;
	}
	cout<<change;
	return 0;
}
