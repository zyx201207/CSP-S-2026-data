#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N],ua[N];
char b[N],ub[N];
long long cnt,r,l,ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.ont","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i = n;i >= 1;i--){
		ua[i] = a[n-i+1];
		ub[i] = b[n-i+1];
	}
	while(r <= n && l <= n){
		if(a[r] < ua[l]){
			ua[l] -= a[r];
			if(ub[l] != b[r]){
				ans += a[r];
			}
			r++;
		}
		else if(a[r] > ua[l]){
			a[r] -= ua[l];
			if(ub[l] != b[r]){
				ans += ua[l];
			}
			l++;
		}
		else{
			if(ub[l] != b[r]){
				ans += ua[l];
			}
			r++;
			l++;
		}
	}
	cout << ans/2;
	return 0;
}
