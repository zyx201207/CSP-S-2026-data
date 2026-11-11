#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m,a[N],ans=0;
map<int,int>v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	v[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(auto j:v)
		{
			int x=j.first,y=j.second;
			if(y==m) ans=max(ans,x);
			if(v.find(x^a[i])==v.end()&&y<m)
			{
				v[x^a[i]]=y+1;	
			}
		}
	}
	cout<<ans;
	return 0;
}