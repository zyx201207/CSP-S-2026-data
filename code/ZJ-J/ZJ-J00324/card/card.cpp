#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[300010],last[300010];
vector<long long> v[300010];
long long dfs(long long k)
{
	if(k<=0) return 0;
	if(s[k]>=0) return s[k];
	s[k]=0;
	for(long long i=0;i<v[k].size();i++)
	  if(last[a[v[k][i]-1]]==v[k][i]-1)
	  {
	  	  s[k]+=dfs(a[v[k][i]-1]);
	  }
	s[k]+=v[k].size();
	return s[k];
}
int main()
{
	freopen("card.in","r",stdin);
//	freopen("card6.in","r",stdin);
	freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		v[a[i]].push_back(i);
	}
	for(long long i=1;i<=m;i++) s[i]=-1000000000;
	for(long long i=n;i>=1;i--)
	if(last[a[i]]==0) last[a[i]]=i; 
	for(long long i=1;i<=m;i++)
	if(i<m) printf("%lld ",dfs(i));
	else printf("%lld\n",dfs(i));
    return 0;
} 
