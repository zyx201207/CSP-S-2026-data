#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node
{
	long long g;
	char s;
}m[N];
int n;
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i].g>>m[i].s;
	}
	int b;
	int r=1,l=n;
	while(r<=l)
	{
		
		if(m[r].g>m[l].g)
		{
			if(m[r].s!=m[l].s) sum+=m[l].g;
			m[r].g-=m[l].g;
		    m[l].g=0;
		}
		else if(m[r].g<m[l].g)
		{
			if(m[r].s!=m[l].s) sum+=m[r].g;
			m[r].g=0;
		    m[l].g-=m[r].g;
		}
		else if(m[r].g==m[l].g)
		{
			if(m[r].s!=m[l].s) sum+=m[r].g;
			m[r].g=0;
			m[l].g=0;
		}
		if(m[r].g==0) r++;
		if(m[l].g==0) l--;
	}
	cout<<sum;
	return 0;
}
