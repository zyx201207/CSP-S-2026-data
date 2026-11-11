#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll pre[N],a[N];
inline bool check(int x){
	for(int i=1,j=i+x-1;j<=n;i++,j++){
		if(a[i]*x-pre[j]+pre[i-1]<=m) return true;
	}
	return false;
}
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll te=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		te+=a[1]-a[i];
	}
	if(te<=m){
		cout<<n;
		return 0;
	}
	ll l=1,ans,r=n,mid;
	ll res=0;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;	
		}
	}
	cout<<ans;
	return 0;
}
