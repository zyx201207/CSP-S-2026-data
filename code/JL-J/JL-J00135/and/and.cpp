#include <bits/stdc++.h>
using namespace std;
#define N 200050
int x[N];
char s1[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>x[i];
	sort(x,x+n,cmp);
	for(int i=0;i<m;i++)
	{
		int weigh=0;
		while(x[i])
		{
			if(i==0)
				s1[weigh]=(x[i]%2)+'0';
			else
				s1[weigh]&=(x[i]%2)+'0';
			x[i]/=2;
			weigh++;
		}
	}
	long long total=0,weiquan=1;
	for(int i=0;i<strlen(s1);i++)
	{
		total+=weiquan*(s1[i]-'0');
		weiquan*=2;
	}
	cout<<total<<endl;
	
	return 0;
}
