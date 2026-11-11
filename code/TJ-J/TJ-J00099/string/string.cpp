#include<bits/stdc++.h>
using namespace std;
int n,ai,p1=1,f1=1;
char c;
long long cnt;
struct z
{
	int ai;
	char c;
} st;
z p[200001],f[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> ai >> c;
		st.ai=ai;
		st.c=c;
		p[i]=st;
		f[n-i+1]=st;
	}
	while(1)
	{
		if(p[p1].ai>f[f1].ai)
		{
			cnt+=f[f1].ai*(p[p1].c!=f[f1].c);
			p[p1].ai-=f[f1].ai;
			f1++;
		}
		else if(p[p1].ai<f[f1].ai)
		{
			cnt+=p[p1].ai*(p[p1].c!=f[f1].c);
			f[f1].ai-=p[p1].ai;
			p1++;
		}
		else
		{
			cnt+=p[p1].ai*(p[p1].c!=f[f1].c);
			f[f1].ai=0;
			p[p1].ai=0;
			p1++;
			f1++; 
		}
		
		if(p1==n+1 || f1==n+1) break;
	}
	cout << cnt/2;
	return 0;
}
