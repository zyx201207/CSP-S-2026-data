#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 5e5+5;
ll n, k=1;
ll m, v, p;
ll a[N], c[N];
ll cnt[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cnt[1]=1;
	c[1]=a[1];
	for(int i=2; i<=n; i++){
		if(a[i]!=a[i-1]){
			k++;
			c[k]=a[i];
		}
		cnt[k]=i;
	}
	for(ll i=2; i<=k; i++){
		v+=(cnt[i-1]-cnt[p])*(c[i]-c[i-1]);
		while(v>m){
			cnt[p]++;
			if(cnt[p]==cnt[p+1]){
				p++;
			}
			v-=c[i]-c[p+1];
		}
		ans=max(ans, cnt[i]-cnt[p]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
