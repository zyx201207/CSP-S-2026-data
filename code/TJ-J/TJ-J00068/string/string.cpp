#include <bits/stdc++.h>
using namespace std;
long long n,w;
long long a[1100];
char b[1100];
long long o,o1,q;
long long sum;
long long sum1[1100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> b[i];
		o += a[i];
		sum1[i] = sum1[i-1]+a[i];
	}
	if (o%2==0){
		o1=o/2;
		for (int i = 1;i <= n;i++){
			if (sum1[i] >= o1){
				w = i;
			}
		}
	}
	else if (o%2==1){
		o1=o/2+1;
		for (int i = 1;i <= n;i++){
			if (sum1[i] >= o1){
				w = i;
			}
		}
	}
	int r = 1,l = n;
	while(l-1!=r){
		if (b[r] == b[l]){
			if (a[r] > a[l]){
				a[r] -= a[l];
				l--;
			}
			else if (a[r]<a[l]){
				a[l] -= a[r];
				r++;
			}
			else if (a[l] == a[r]){
				r++;
				l--;
			}
		}
		if (b[r]!=b[l]){
			if (a[r] > a[l]){
				sum+=a[l];
				a[r] -= a[l];
				l--;
			}
			else if (a[r]<a[l]){
				sum+=a[r];
				a[l] -= a[r];
				r++;
			}
			else if (a[l] == a[r]){
				sum+=a[r];
				r++;
				l--;
			}
		}
	}
	if (b[r] == b[l]){
		cout << sum;
		return 0;
	}
	cout << sum+min(a[r],a[l]);
}

