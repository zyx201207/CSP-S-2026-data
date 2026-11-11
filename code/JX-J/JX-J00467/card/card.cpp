#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool vis[500010];
int tt[500010];
bool bj=1;
map<int,vector<int>>t;
bool cmp(vector<int> x,vector<int> y)
{
		return x[0]<y[0];
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	
	t[a[i]].push_back(i);
}
for(int i=1;i<=n;i++)
{
	if(!vis[a[i]])
	{
	vis[a[i]]=1;
	sort(t[a[i]].begin(),t[a[i]].end());
	}
}
/*for(int i=1;i<=m;i++)
{
	for(int j=i+1;j<=n;j++)
	{
		if(a[j]!=a[j-1])
		{
			
			tt[j-1]++;
			bj=0;
		}else
		{
			if(bk==1)
			{
				
			}
			bj=1;
		}
	}
	
}*/
cout<<n;
return 0;
}
