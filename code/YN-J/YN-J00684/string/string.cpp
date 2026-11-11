#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector<int>
const int N=2e5+5;
int n,len,l=1,r,v[N],flag;
char c[N];
vt ans;
vt add(vt a,int bv)
{
	if(!flag) flag=1,ans.pop_back();
	vt res;
	vt b;
	while(bv)
	{
		b.push_back(bv%10);
		bv/=10;
	}
	if(a.size()<b.size()) swap(a,b);
	int t=0;
	for(int i=0;i<a.size();i++)
	{
		t+=a[i];
		if(i<b.size()) t+=b[i];
		res.push_back(t%10);
		t/=10;
	}
	if(t) res.push_back(t);
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ans.push_back(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>c[i];
	}
	r=n;
	
	while(l<r)
	{
		if(v[l]<v[r])
		{
			if(c[l]!=c[r])
			{
				ans=add(ans,v[l]);
			}
			v[r]-=v[l++];
		}else
		{
			if(c[l]!=c[r])
			{
				ans=add(ans,v[r]);
			}
			v[l]-=v[r--];
		}
	}
	for(int i=ans.size()-1;i>=0;i--)
	{
		cout<<ans[i];
	}
	return 0;
}