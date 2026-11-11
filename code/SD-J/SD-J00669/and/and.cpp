#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int maxx=0;
void dfs(int u,int t,int cnt)
{
	if(t==m)
	{
		maxx=max(maxx,cnt);
		return;
	}
	for(int i=u+1;i<=n-(m-t);i++)
	{
		dfs(i,t+1,cnt&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<maxx<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
