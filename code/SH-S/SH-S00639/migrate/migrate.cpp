#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+9;
const ll INF=1e18;
ll c,n,D,x[N],L[N],R[N];//左边，右边能一次达到的距离
ll f[N],cnt[N];
void solveDCSL(){
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll num=D/(x[2]-x[1]);
	if(num<=1) cout<<"0\n";
	else cout<<max(0ll,n-2*num+1)<<"\n";
	return;
}
void solve2D(){
	for(int i=1;i<=n;i++){
		ll l=1,r=i,mid=1;L[i]=i,R[i]=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(x[i]-x[mid]<=D) r=mid-1,L[i]=mid;
			else l=mid+1;
		}
		l=i,r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(x[mid]-x[i]<=D) l=mid+1,R[i]=mid;
			else r=mid-1;
		}
	} 
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(R[i]==i) continue;
		if(R[i]-2<i) continue;
		if(R[R[i]-2]<R[R[i]-1]) ans+=(R[R[i]-1]-R[R[i]-2]);
	}
	cout<<ans<<"\n";
	return;
}
void solve(){
	cin>>n>>D;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c==11||c==12) solveDCSL();//等差数列
	else if(c==13||c==14) solve2D();
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			ll l=1,r=i,mid=1;L[i]=i,R[i]=i;
			while(l<=r){
				mid=(l+r)>>1;
				if(x[i]-x[mid]<=D) r=mid-1,L[i]=mid;
				else l=mid+1;
			}
			l=i,r=n;
			while(l<=r){
				mid=(l+r)>>1;
				if(x[mid]-x[i]<=D) l=mid+1,R[i]=mid;
				else r=mid-1;
			}
		} 
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) f[j]=INF,cnt[j]=1;
			cnt[i]=1;f[i]=0;
			for(int j=i+1;j<=n;j++){
				for(int k=max(i*1ll,L[j]);k<=j;k++){
					if(f[j]<f[k]+1) break;
					else if(f[j]==f[k]+1) cnt[j]+=cnt[k];
					else f[j]=f[k]+1,cnt[j]=cnt[k];
					if(cnt[j]>2) break;
				} 
			}
			for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<endl;
	} 
	else solve2D();
	return;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>c>>T;
	while(T--) solve();
	return 0;
} 
