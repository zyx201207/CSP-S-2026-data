#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=5*1e5+1;
long long n,m,ans;
long long Cry[MAXN];
long long F(int,long long);

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>Cry[i];
	sort(Cry+1,Cry+n+1);
	ans=F(n,0);
	cout<<ans;
	return 0;
}

long long F(int x,long long rn)
{
	if(x==0)return rn;
	int nxt=x;
	long long r=0;
	long long pnt=m;
	for(int i=x;i>=1;i--)
	{
		long long dif=Cry[x]-Cry[i];
		pnt-=dif;
		if(!dif)nxt--;
		if(pnt>=0)
			r++;
		else
			break;
	}
	r=max(r,rn);
	return F(nxt,r);
}