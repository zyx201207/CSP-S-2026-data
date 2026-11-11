#include <bits/stdc++.h>
using namespace std; 
long long n,m,max1=LLONG_MIN,a[200050];
void dfs(int k,int cnt,long long sum){
    if(cnt==m){
	max1=max(max1,sum);
	return ;
    }
    for(int i=k;i<=n;i++)
    {
       dfs(i+1,cnt+1,sum&a[i]);
	}
}
int main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++)cin>>a[i];
   dfs(1,0,INT_MAX);
   cout<<max1;
   return 0;
}
