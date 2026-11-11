#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,ans;
ll a[N],f[N];
bool check(int x){
	for (int l=1,r=x;l<=n&&r<=n;l++,r++){
		if (a[r]*x-(f[r]-f[l-1])<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=1,r=n;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}