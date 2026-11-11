#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll a[N];
int n,m;
ll st[N],rst[N],top;
bool check(ll k){
//	cout<<k<<":\n";
	rep(s,1,n-m){
		top=0;
		st[++top]=s;
		rst[top]=a[s];
		int cnt=1;
	//	int cccnnnttt=0;
		rep(i,s+1,n){
	//		cccnnnttt++;
	//		if(cccnnnttt>10)exit(0);
//			cout<<i<<" "<<cnt<<" "<<top<<" "<<st[top]<<" "<<rst[top]<<" "<<a[st[top]]<<"\n";
			if(rst[top]<k&&top>1&&cnt>1){
				top--;
				cnt--;
	//			cout<<"reback\n";
				continue;
			}
			if(rst[top-1]&a[i]>rst[top]&&top>1&&cnt>1){
				st[top]=i;
				rst[top]=rst[top-1]&a[i];
			}
			else{
				st[++top]=i;
				rst[top]=rst[top-1]&a[i];
				cnt++;
			}
			if(cnt==m){
				if(rst[top]>=k){
					return 1;
				}
			}
		}
	}
	return 0;
}
ll getones(ll x){
	ll res=0;
	while(x){
		res+=x&1;
		x/=2;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll maxn=0;
	rep(i,1,n){
		cin>>a[i];
		if(getones(a[i])>getones(maxn)&&i<=n-m){
			maxn=a[i];
		}
	}
//	rep(i,1,n){
//		cout<<a[i]<<" ";
//	}cout<<"\n";
	ll l=0,r=maxn*2;
	ll ans=-inf;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

