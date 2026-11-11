#include<bits/stdc++.h>
#define int long long
#define sor(i,l,r) for(int i=(l);i<=(r);i++)
#define ros(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
namespace Eaux{
	bool check(int mid,int i,vector<int> &s,int m){
		if((i-mid)*(s[i]-s[i-1])-(s[i-1]-s[mid-1])<=m) return true;
		else return false;
	}
	void work(){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1),s(n+1);
		sor(i,1,n) cin>>a[i];
		sort(a.begin()+1,a.end());
		sor(i,1,n) s[i]=s[i-1]+a[i];
		int res=1;
		sor(i,2,n){
			int l=1,r=i-1,ans=1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid,i,s,m)){
					r=mid-1;
					ans=i-mid+1;
				}
				else l=mid+1;
			}
			res=max(res,ans);
		}
		cout<<res;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Eaux::work();
	return 0;
}
