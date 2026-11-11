#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,b,l,t,c,i,ans=0;
	int a[300000];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	l=1;
	b=1;
	sort(a,a+n+1);
	t = a[n];
	ans=0;
	while (t>1){
		t/=2;
		b*=2;
	}
	while (b>0){
		i=n;
		c=0;
		while (a[i]>=b and i>=l){
			c++;
			i--;
		}
		if (c>=m){
			l=i+1;
			ans+=b;
		}
		for (i=i+1;i<=n;i++){
			a[i]-=b;
		}
		b/=2;
		sort(a+l,a+n+1);
	}
	cout << ans;
	return 0;
}
