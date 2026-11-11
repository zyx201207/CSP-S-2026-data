#include<bits/stdc++.h>
using namespace std;
const int N=500009;
typedef long long ll;
ll l,r,ans,cnt,n,m,a[N];
bool stairs(){
	for (int i=1;i<n-1;i++){
		if (a[i]-a[i+1]!=a[i+1]-a[i+2]) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (a[n]==a[1]){
		cout<<n<<endl;
		return 0;
	}
	if (stairs()){
		cnt=0;
		ans=1;
		for (int i=n-1;i>=1;i--){
			cnt+=a[n]-a[i];
			if (cnt>m) break;
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	l=r=1;
	while(r<n){
		r++;
		cnt+=(r-l)*(a[r]-a[r-1]);
		while(cnt>m){
			l++;
			cnt-=a[r]-a[l-1];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
