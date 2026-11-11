#include <bits/stdc++.h>
using namespace std;
long long t;
long long num[200005];
char z[200005];
long long ans;
long long lm,rm;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	for (int i=1;i<=t;i++){
		cin >> num[i] >> z[i];
	}
	long long l=1,r=t;
	lm=num[1];
	rm=num[t];
	while (l<r){
		if (lm>rm){
			lm-=rm;
			if (z[l]!=z[r]){
				ans+=rm;
			}
			r--;
			rm=num[r];
		}
		else if (rm>lm){
			rm-=lm;
			if (z[l]!=z[r]){
				ans+=lm;
			}
			l++;
			lm=num[l];
		}
		else{
			if (z[l]!=z[r]){
				ans+=lm;
				
			}
			l++;
			r--;
			lm=num[l];
			rm=num[r];
		}
	}
	cout << ans;
	return 0;
}