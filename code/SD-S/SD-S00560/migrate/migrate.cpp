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
	ll d,a[2000005];
	int L[2000005],R[2000005];
	int f1[2000005],f2[2000005];
	ll s1[2000005],s2[2000005];
	bool check(int i,int j){
		if(i==0||j==n+1) return 0;
		return (a[j]-a[i])<=d;
	}
	void solve(){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=n+1;i++){
			L[i]=0;
			R[i]=n+1;
		}
		for(int i=1;i<=n;i++){
			L[i]=L[i-1];
			while(!check(L[i],i)) L[i]++;
//			int l=1,r=i;
//			while(l<=r){
//				int mid=(l+r)/2;
//				if(a[i]-a[mid]<=d){
//					L[i]=mid;
//					r=mid-1;
//				}else l=mid+1;
//			}
//			l=i;
//			r=n;
//			while(l<=r){
//				int mid=(l+r)/2;
//				if(a[mid]-a[i]<=d){
//					R[i]=mid;
//					l=mid+1;
//				}else{
//					r=mid-1;
//				}
//			}
//			cout<<L[i]<<" "<<R[i]<<endl;
		}
		for(int i=n;i;i--){
			R[i]=R[i+1];
			while(!check(i,R[i])) R[i]--;
		}
		L[n+1]=0;
		R[0]=n+1;
		for(int i=0;i<=n+1;i++){
			f1[i]=0;
			f2[i]=0;
			s1[i]=0;
			s2[i]=0;
		}
		for(int i=1;i<=n;i++){
			int l=L[i],r=L[i+1]-1;
			if(l<=r){
				f1[i]+=f1[l];
				f1[i]+=(r-l);
			}
			f1[i]++;
//			cout<<f1[i]<<endl;
		}
//		cout<<endl;
		for(int i=n;i;i--){
			int l=R[i-1]+1,r=R[i];
			if(l<=r){
				f2[i]+=f2[r];
				f2[i]+=(r-l);
			}
			f2[i]++;
//			cout<<f2[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			s1[i]=f1[i]+s1[i-1];
			s2[i]=f2[i]+s2[i-1];
		}
		ll ans=0;
		for(int i=3;i<n;i++){
			if(a[i]-a[i-1]>d) continue;
			if(a[i]-a[i-2]>d) continue;
			if(a[i+1]-a[i-1]>d) continue;
			ll sum1=0,sum2=0;
			int r=min(L[i+1]-1,i-2),l=min(L[i],i-2);
			if(l>r) continue;
			if(l==L[i-1]){
				sum1+=f1[l];
				sum1+=(r-l);
			}else sum1+=(r-l+1);
			l=max(R[i-2]+1,i+1);
			r=max(R[i-1],i+1);
			if(l>r) continue; 
			if(r==R[i]){
				sum2+=f2[r];
				sum2+=(r-l);
			}else sum2+=(r-l+1);
			ans+=sum1*sum2;
		}
		cout<<ans<<endl;
	}
	void main(){
		int c,T;
		cin>>c>>T;
		while(T--) solve();
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}

