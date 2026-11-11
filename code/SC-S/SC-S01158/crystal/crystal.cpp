#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],b[N];
ll n,m,m2;
int erfen(long long x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>=x){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return l-1;
}
map<char,long long> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	m2=m;
	ll sum=0;
	ll maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		sum+=a[i];
		mp[a[i]]++;
		maxn=max(maxn,mp[a[i]]);
	}
	sort(a+1,a+1+n);
	sum/=n;
	int t=lower_bound(a+1,a+1+n,sum)-a;
	int l=t,r=t+1;
	while(m){
		if(a[t]-a[l]<=a[r]-a[t]&&m>=a[t]-a[l]&&l>=1){
			m-=a[t]-a[l];
			a[l]=a[t];
			l--;
		}else if(a[t]-a[l]>a[r]-a[t]&&m>=a[r]-a[t]&&r<=n){
			m-=a[r]-a[t];
			a[r]=a[t];
			r++;
		}else{
			break; 
		}
	}
	ll ans1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[t]){
			ans1++;
		}
	}
	for(int i=1;i<=n;i++)a[i]=b[i];
	m=m2;
	t=erfen(sum);
	l=t,r=t+1;
	while(m){
		if(a[t]-a[l]<=a[r]-a[t]&&m>=a[t]-a[l]&&l>=1){
			m-=a[t]-a[l];
			a[l]=a[t];
			l--;
		}else if(a[t]-a[l]>a[r]-a[t]&&m>=a[r]-a[t]&&r<=n){
			m-=a[r]-a[t];
			a[r]=a[t];
			r++;
		}else{
			break;
		}
	}
	ll ans2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[t]){
			ans2++;
		}
	}
	ll ans=max({ans1,ans2,maxn});
	cout<<ans<<'\n';
	return 0;
} 