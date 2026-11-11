#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans,ry,ll,ll2,rr,rr2;
void solve1(){
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++)
			cin >> x[i];
		if(d<x[3]-x[1]||d>=x[n/2+2]-x[1]) cout << 0 << '\n';
		else cout << n-d/(x[2]-x[1])*2+1 << '\n';
	}
}
void solve2(){
	while(t--){
		cin >> n >> d;
		int i;
		for(i=1;i<=n;i++)
			cin >> x[i];
		for(i=1;ry==0;i++) if(x[i+1]-x[1]>d) ry=i;
		for(i=1;x[ry+1]-x[i]>d;i++) continue;
		ll=i;
		for(i;x[ry+2]-x[i]>d;i++) continue;
		ll2=i;
		for(i=n;x[i]-x[ry-1]>d;i--) continue;
		rr=i;
		for(i;x[i]-x[ry-2]>d;i--) continue;
		rr2=i;
		cout << (rr-rr2)*(ll-1)+(ll2-ll)*(n-rr);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12) solve1();
	else if(c==13||c==14) solve2();
	return 0;
}
