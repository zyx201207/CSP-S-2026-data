#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
const ll N=5e5+10,INF=-1e12;
ll a[N],tr[N],pre[N];
void build(int l,int r,int id){
	if(l==r){
		tr[id]=a[l];
		return;
	}
	int mid=(r-l)/2+l;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	tr[id]=max(tr[id*2],tr[id*2+1]);
}
ll query(ll l,ll r,ll L,ll R,ll id){
	if(l>=L&&r<=R){
		return tr[id];
	}
	if(l>R||r<L) return INF;
	ll mid=(r-l)/2+l;
	return max(query(l,mid,L,R,id*2),query(mid+1,r,L,R,id*2+1));
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	bool A=1;
	ll mx=INF,ans=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=0;
		}pre[i]=pre[i-1]+a[i];
		mx=max(mx,a[i]);
	}
	if(A){
		if(n%2==1){
			ll l=n/2+1;
			ll r=n/2+1;
			ll diff=1;
			ll add=0;
			while(add<=m&&l>=2&&r<n){
				if(add+diff<=m){
					l--;
					add+=diff;
				}else break;
				if(add+diff<=m){
					r++;
					add+=diff;
				}else break;
				diff++;
			}
			cout<<r-l+1;
		}else{
			ll l=n/2;
			ll r=n/2;
			ll diff=1;
			ll add=0;
			while(add<=m&&l>=2&&r<n){
				if(add+diff<=m){
					l--;
					add+=diff;
				}else break;
				if(l<2) break;
				if(add+diff<=m){
					r++;
					add+=diff;
				}else break;
				diff++;
			}
			if(add+diff<=m){
				r++;
				add+=diff;
			}
			ll ans=r-l+1;
			l=n/2+1;
			r=n/2+1;
			diff=1;
			add=0;
			while(add<=m&&l>=2&&r<n){
				if(add+diff<=m){
					r++;
					add+=diff;
				}else break;
				if(r>=n) break;
				if(add+diff<=m){
					l--;
					add+=diff;
				}else break;
				diff++;
			}
			if(add+diff<=m){
				l--;
				add+=diff;
			}
			ans=min(ans,r-l+1);
			cout<<ans;
		}
	}else if(mx<=100){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=-100;j<=100;j++){
				if(a[i]>j) continue;
				ll tmp=m,now=i;
				while(tmp-(j-a[now])>=0&&j>=a[now]&&now<=n){
					tmp-=(j-a[now]);
					now++;
				}
				ans=max(ans,now-i);
				//cout<<"right:"<<i<<" "<<j<<"\n";
			}
		}cout<<ans;
	}else{
		build(1,n,1);
		pre[0]=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				ll mx=query(1,n,i,j,1);
				ll sum=pre[j]-pre[i-1];
				ll diff=mx*abs(j-i+1)-sum;
				if(diff<=m) ans=max(ans,abs(j-i+1));
			}
		}cout<<ans;
	}
	return 0;
}
