#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define pb push_back
#define pii pair<ll,ll>
#define p_q priority_queue
#define mk make_pair
#define endl '\n'
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))
namespace cute_fzj_kuai_ruarua{
	int n;
	ll m,a[500005];
	ll sum[500005];
	void main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=1,r=i,pos=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
					pos=mid;
					r=mid-1;
				}else l=mid+1; 
			}
			ans=max(ans,i-pos+1);
		}
		cout<<ans;
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}

