#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long sum,n;
long long a[N];
char c[N];
struct edge
{
	long long gs;
	char c;
} s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i].gs=a[i];
		s[i].c=c[i];
	}
	int k=1;
	while(k<=n)
	{
		if(s[k].c!=s[n+1-k].c)
		{
			int x=min(s[k].gs,s[n+1-k].gs);
			sum+=x;
			if(s[k].gs==x) k++;
			else n--;
			s[k]={s[k].gs-x,s[k].c};
			s[n+1-k]={s[n+1-k].gs-x,s[n+1-k].c};
		}
		k++;
	}
	cout<<sum;
	return 0;
} 
