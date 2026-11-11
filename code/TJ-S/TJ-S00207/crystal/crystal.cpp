#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const N=500010;
ll const INF=(1e12)+10;
int n;
ll res;
ll m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	a[0]=a[1];
	ll cnt=0,w=0;
	int l=1,r=1;
	for (;r<=n;r++){
		w+=(a[r]-a[r-1])*cnt,cnt++;
		while (w>m){
			w-=a[r]-a[l],cnt--,l++;
		}
		if (cnt>res) res=cnt;
	}
	printf("%lld",res);
	
	return 0;
}

