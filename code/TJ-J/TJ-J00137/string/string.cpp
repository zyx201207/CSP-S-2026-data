#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],ans;
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
	}
	long long l = 1,r = n;
	for(long long i=1;i<=n;i++){
		if(l == r)break;
		long long mi = min(a[l],a[r]);
		if(mi == a[l]){
			if(c[l] != c[r])
				ans += a[l];
			a[r] -= a[l];
			l ++;
		}
		else{
			if(c[l] != c[r])
				ans += a[r];
			a[l] -= a[r];
			r--;
		}
		
	}
	cout<<ans;
	return 0;
}
