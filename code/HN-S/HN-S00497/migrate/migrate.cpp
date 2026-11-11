#include<bits/stdc++.h>
using namespace std;
const int N=2000100;
typedef long long ll;
#define endl '\n'

struct info{
	int r,x;
}a[N];

int t;
ll n,d,x[N];

inline int check(int w){
	int l=0,r=n+1;
	while (l+1<r){
		int mid=(l+r)>>1;
		if (x[mid]<=a[w].r)
			l=mid;
		else
			r=mid;
	}
	return l;
}

inline void work(){
	cin >> n >> d;
	for (int i=1;i<=n;i++){
		cin >> x[i];
		a[i].r=x[i]+d;
		a[i].x=0;
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		int id=check(i);
		a[i].x=(id-i);
	}
	ll l=1,r=2;
	ll s=a[1].x;
	if (s==2 && x[r]-x[l]<d)
		ans++;
	while (r<=n){
		if (l>=r)
			s+=a[++r].x;
		else if (x[r]-x[l]>d)
			s-=a[++l].x;
		else if (s<2)
			s+=a[++r].x;
		else
			s-=a[++l].x;
		if (s==2)
			ans++;
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t >> t;
	while (t--) work();
	return 0;
}

