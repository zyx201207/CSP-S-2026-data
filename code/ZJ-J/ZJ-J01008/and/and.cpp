#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
char x[200009][100],y[100];
priority_queue<int>h;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(x,0,sizeof(x));
	for(int i=1;i<=n;i++)
	{
		int w;
		scanf("%d",&a[i]);
		w=a[i];
		h.push(a[i]);
		int len=0;
		while(a[i]>0)
		{
			x[w][++len]=a[i]%2;
			a[i]/=2;
		}
	}
	int xx=h.top();
	h.pop();
	int len=strlen(x[xx]);
	for(int i=1;i<=len;i++)
	{
		y[i]==x[xx][i];
	}
	m=m-1;
	while(m--)
	{
		int yy=h.top();
		h.pop();
		int lenxx=strlen(y);
		int lenyy=strlen(x[yy]);
		for(int i=1;i<=max(lenxx,lenyy);i++)
		{
			if(y[i]=='1' && x[yy][i]=='1') y[i]=1;
			else y[i]=0;
		}
	}
	int lena=strlen(y);
	long long ans=0,sum=1;
	for(int i=1;i<=len;i++)
	{
		ans+=sum*(y[i]-'0');
		sum*=2;
	}
	printf("%d\n",ans);
	return 0;
}