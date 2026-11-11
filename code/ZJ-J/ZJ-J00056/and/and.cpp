#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,m;
struct st
{
	long long x;
	char ch[31];
}ar[N];
bool cmp(st a,st b)
{
	int len=max(strlen(a.ch),strlen(b.ch));
	for(int i=len;i>=1;i--)
	{
		if(a.ch[i]==b.ch[i]) continue;
		else return a.ch[i]>b.ch[i];
	}
	return a.x>b.x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i].x;
		memset(ar[i].ch,0,sizeof(ar[i].ch));
		long long tmp=ar[i].x;
		int j=1;
		while(tmp>0)
		{
			int op=tmp%2;
			ar[i].ch[j]=op;
			j++;
			tmp/=2;
		}
	}
	sort(ar+1,ar+1+n,cmp);
	ans=ar[1].x;
	for(int i=1;i<=m;i++)
	{
		ans&=ar[i].x;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
