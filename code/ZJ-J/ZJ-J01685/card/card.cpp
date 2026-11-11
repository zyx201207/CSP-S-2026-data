#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define fr(x) freopen(#x".in","r",stdin)
#define fw(x) freopen(#x".out","w",stdout)
using namespace std;
using db=double;
using ll=long long;
using ull=unsigned long long;
using PI=pair<int,int>;
const int N=5e5+5;
int n,m;
int a[N],bo[N],ans[N];
vector<int> vc;
int main()
{
	fr(card);
	fw(card);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int _=1;_<=n;_++)
	{
		vc.clear();
		for(int i=1;i<=m;i++) bo[i]=0;
		for(int i=_;i<=n;i++)
		{
			if(bo[a[i]])
			{
				while(vc.back()!=a[i]) 
				{
					bo[vc.back()]=0;
					vc.pop_back();
				} 
				vc.pop_back();
			}	
			bo[a[i]]=1;
			vc.pb(a[i]);
		}
		for(int i=1;i<=m;i++) 
			if(bo[i])
				ans[i]++;	
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" \n"[i==m];
	return 0;
}