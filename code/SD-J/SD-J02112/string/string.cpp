#include<bits/stdc++.h>
using namespace std;
long long n,p,cnt,ans;char k;string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>k;
		cnt+=p;
		for(int i=1;i<=p;i++)s+=k;
	}
	for(int i=0;i<cnt/2;i++)ans+=(s[i]!=s[cnt-i]);
	cout<<ans;
	return 0;
} 
/*
Wrong Code
#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long st,ed;
	char c;
};
long long n,p,ans,ap[1000010],cnt,md;node a[1000010];char k,ak[1000010]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ap[i]>>ak[i];
		cnt+=ap[i];
	}
	n+=2; 
	for(int i=1;i<=n;i++)
	{
		a[i].st=p+1;
		p=ap[i];
		k=ak[i];
		if(a[i].st<=cnt-cnt/2&&a[i].st+p-1>=cnt/2)
		{
			a[i].c=k;
			a[i++].ed=cnt/2;
			md=i;
			a[i].st=cnt/2+1;
			i++;
			p=cnt-cnt/2+1;
		}
		p=a[i].st+p-1;
		a[i].ed=p;
		a[i].c=k;
	}
	int v=n;
	for(int i=1;i<=md;i++)
	{
		for(v;(cnt-a[v].ed+1<=a[i].ed)&&v>md;v--)
		{
			ans+=(a[i].c!=a[v].c)*(max(a[v-1].ed,cnt-a[i].st+1)-a[v].ed);
		}
	}
	cout<<ans;
	return 0;
} */
