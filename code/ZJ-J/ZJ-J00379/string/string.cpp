#include<bits/stdc++.h>
using namespace std;
int n;
struct R{
	long long cs;
	char fh;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].cs >> a[i].fh;
	long long l=1,r=n,l1=0,l2=0;
	long long ans=0;
	while(l<r){
		long long qd=min(a[l].cs-l1,a[r].cs-l2);
		if(a[l].fh!=a[r].fh) ans+=qd;
		l1+=qd,l2+=qd;
		if(l1==a[l].cs) l1=0;
		if(l2==a[r].cs) l2=0;
		if(l1==0 && l2==0) l++,r--;
		else if(l1==0) l++;
		else r--;
	}
	cout << ans;
	return 0;
}
