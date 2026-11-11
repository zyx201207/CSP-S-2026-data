#include<bits/stdc++.h>
using ll=long long;

using namespace std;

const int N=2e5+5; 
ll ans,sum;
struct point {
	int p,ty;
}a[N];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		char c;
		cin>>a[i].p>>c;
		a[i].ty=(c-'a'+1),sum+=a[i].p;
	} 
	ll mid=(sum+1)>>1,res=0;
	int now=1,en=n;
	while(res+a[now].p<=mid) {
		res+=a[now].p;
		if(a[now].p>=a[en].p) {
			int t=a[now].p;
			while(t) {
				if(t-a[en].p<0) {
					if(a[en].ty!=a[now].ty)ans+=t;
					a[en].p-=t;
					break;
				}
				else {
					t-=a[en].p;
					if(a[en].ty!=a[now].ty)ans+=a[en].p;
				}
				en--;
			}
		}
		else {
			if(a[now].ty!=a[en].ty) ans+=a[now].p;
			a[en].p-=a[now].p;
		}
		now++;
	}
	if(now!=en) {
		while(en>now) {
			if(a[now].ty!=a[en].ty) ans+=a[en].p;
			en--;
		}
	}
	cout<<ans;
	return 0;
}
