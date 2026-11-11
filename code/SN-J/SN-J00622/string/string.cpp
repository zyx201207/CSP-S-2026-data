#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int n;
bool f()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0) return false;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	cin>>n;
	int head=1,tail=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	while(head!=tail)
	{
		if(a[head]==0) head++;
		if(a[tail]==0) tail--;
		long long mi=min(a[head],a[tail]);
		a[head]-=mi;
		a[tail]-=mi;
		if(s[head]!=s[tail]) ans+=mi;
		if(a[head]==0&&a[tail]==0)
		{
			if(f()) break;
		 }
	}
	cout<<ans;
	return 0;
}
