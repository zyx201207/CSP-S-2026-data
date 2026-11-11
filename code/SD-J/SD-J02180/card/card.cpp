#include <bits/stdc++.h>
#define ll long long
const int mxn=555555;
const int mxm=333333;
using namespace std;
int a[mxn];
int ans[mxm];
int beh[mxn];
int las[mxn];
int fir[mxn];
struct interval
{
	int l,r;
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) fir[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		beh[a[i]]=i;
	}
	deque<interval> v;
	for(int i=1;i<=n;i++)
	{
		if(las[a[i]]!=0)
		{
			v.push_back({las[a[i]],i-1});
		}
		las[a[i]]=i;
	}
	sort(v.begin(),v.end(),[](interval x,interval y){return x.l<y.l;});
	int N=v.size();
	int has=1;
	for(int i=0;i<N;i++)
	{
		//cout<<v[i].l<<" "<<v[i].r<<endl;
		for(int i1=has;i1<=v[i].l;i1++) fir[i1]=i;
		has=v[i].l+1;
	}
	for(int k=1;k<=n;k++)
	{
	for(int i=k;i<=n;)
	{
		int idx=fir[i];
		if(idx==-1)
		{
			for(int j=i;j<=n;j++) ans[a[j]]++;
			break;
		} 
		auto interv=v[idx];
		if(interv.l>i)
		{
			for(int j=i;j<interv.l;j++)
			{
				ans[a[j]]++;
			}
		}
		int r=interv.r;
		int new_l=r+1;
		i=new_l;
	}
}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
