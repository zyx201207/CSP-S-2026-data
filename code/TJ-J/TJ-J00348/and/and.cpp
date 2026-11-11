#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],ans;
ll ad(int l,int cnt){
	if (cnt==1) return a[l];
	ll sum=0;
	for (int i=l+1;i<=n;i++){
		sum=max(sum,a[i]&ad(i+1,cnt-1));
	}return sum;
}bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}if (m==n){
		for (int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else if (m==1){
		for (int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}else if (m==2){
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(n<=20){
		for (int i=0;i<n;i++){
			ans=max(ans,ad(i,m));		
		}
	}else{
		sort(a+1,a+1+n,cmp);
		ans=a[n]&a[n-1];
	}
	cout<<ans<<"\n";
	return 0;
}

