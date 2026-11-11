#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+4;
int n;
long long m;
long long a[N];

bool check(int x){
	long long co = 0;
	long long mx = -1;
	for(int i = 1;i <= x;i++){
		mx = max(a[i],mx);
	}
	for(int i = 1;i <= x;i++){
		co += mx-a[i];
	}
	if(co <= m) return 1;
	for(int l = 2,r = x+1;r <= n;l++,r++){
		co -= mx-a[l-1];
		co += (a[r]-mx)*(x-1);
		mx = a[r];
		if(co <= m){
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 0,r = n+1,ans;
	while(l <= r){
		int mid = l+((r-l)>>1);
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
}
