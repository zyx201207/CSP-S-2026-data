#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}namespace ZXY{
	const int N=5e5+7;
	typedef long long ll;
	ll m,a[N];int n;
	ll pre[N],res=0;
	map<ll,int>cnt;
	map<ll,bool>vis; 
	void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>n>>m;
		rep(1,n,i)cin>>a[i],cnt[a[i]]++;
		sort(a+1,a+n+1);
		rep(1,n,i)pre[i]=pre[i-1]+a[i];
		rep(1,n,i){
			if(vis.count(a[i]))continue;
			int l=1,r=i,ans=i;
			while(l<=r){
				int mid=l+r>>1;
				ll cha=1ll*(i-mid)*a[i]-
				(pre[i-1]-pre[mid-1]);
				if(cha<=m)ans=mid,r=mid-1;
				else l=mid+1; 
			}res=max(res,(ll)i-ans+cnt[a[i]]);
			vis[a[i]]=1;
		}cout<<res;
	}
}
int main(){fre();ZXY::solve();}

