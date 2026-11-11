#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int C,T,n,d,b[N];
ll a[N],ans;
int search(ll num){
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<=num) l=mid+1;
		else r=mid-1; 
	}
	return l-1;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	int mx=0,lst=0;
	for(int i=1;i<=n;i++){
		int pos=search(a[i]+d);
		if(pos>mx){
			mx=max(mx,pos);
			if(i==b[lst]) b[lst]=pos;
			else{
				lst=i;
				b[i]=pos;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(!b[i]||b[i]==i) continue;
		if(b[i]<b[b[i]-1]) ans+=1LL*(b[i]-i-1)*(b[b[i]-1]-b[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0; 
}