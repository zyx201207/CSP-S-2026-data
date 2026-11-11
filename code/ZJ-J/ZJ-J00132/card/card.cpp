#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],b[5005],ans[5005];
bool t[5005],cx[5005];
int wz[5005];
void yx(int i)
{
	vector<int> v;
	v.clear();
	memset(t,0,sizeof(t));
	memset(cx,0,sizeof(cx));
	memset(wz,0,sizeof(wz));
	for(int j=i;j<=n;j++)
	{
		int now=a[j];
		if(!cx[now])
		{
			v.push_back(now);
			wz[now]=v.size()-1;
			cx[now]=1;
		}else
		{
			for(;wz[now]+1<v.size();)
			{
				cx[v.size()-1]=0;
				wz[v.size()-1]=0;
				v.pop_back();
			}
		}
	}
	for(int j=0;j<v.size();j++)
	  t[v[j]]=1;
	for(int i=1;i<=m;i++)
	  ans[i]+=t[i];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  yx(i);
	for(int i=1;i<=m;i++)
	  cout<<ans[i]<<' ';
	return 0;
}