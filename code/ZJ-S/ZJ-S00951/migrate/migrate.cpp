#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
const int mo=1e9+7;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=2e6+5;
int c,T,n,d,a[N];
vector<int>ans;
bool low(int l,int x){
	int r=n,aa=0;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<x) l=mid+1,aa=mid;
		else r=mid-1; 
	}
	return aa+1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;int res=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int len=4;len<=n;len++)
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1,now=a[i];
				ans.clear();
				int to=a[j];
				while(now>=to){
					int nnow=now+d;
					int id=low(now,nnow);
					ans.pb(id);
					now=a[id];
				}
				ans.pop_back();
				if(ans.empty()) continue;
				int cnt=0;
				for(int k=1;k<ans[0];k++){
					bool ff=1;
					int lid=0;
					for(auto id:ans){
						if(lid==0) continue;
						if(a[id-k]==a[i]){
							ff=0;
							break;
						}
						if(abs(a[id-k]-a[lid-k])>d){
							ff=0;
							break;
						}
						lid=id;	
					}
					if(abs(a[ans[0]-k]-a[i])>d) ff=0;
					if(abs(a[ans.back()-k]-a[j])>d) ff=0;
					if(ff==1) cnt+=1;
					if(cnt>1)break;
				}
				if(cnt==1) res++;
			}
		cout<<res<<'\n';
	}
	return 0;
}
