#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
long long s[N];
bool check(int x,int y,long long w){
	long long ret=1ll*(y-x+1)*w-(s[y]-s[x-1]);
	return ret<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i,a[i])) r=mid;
			else l=mid+1;
		}
//		cout << l << ' ' << i << '\n';
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
