#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[200100],n,m,maxn=0;
void dfs(int pos,int yx,int ans) 
{
	if(yx==m) 
	{
		maxn=max(maxn,ans);
//		cout<<ans;
		return ;
	}
	if(yx+n-pos+1<m) return;
//	cout<<pos<<' '<<yx<<" "<<ans<<endl;
//	cout<<pos<<' '<<yx<<endl;
	for(int i=pos;i<=n;i++)
	dfs(i+1,yx+1,yx==0?a[i]:ans&a[i]);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1,0,0);
	cout<<maxn;
	
	return 0;
 } 
