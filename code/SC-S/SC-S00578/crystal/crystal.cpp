#include <bits/stdc++.h>
using namespace std;

long long n,m,ans = 1;
long long a[500005];
int f(int x){
	long long cnt = 0,sum = 1;
	for(int i = x-1;i >= 1;i--){
		if(a[x]-a[i] <= m-cnt){
			sum++;
			cnt+=a[x]-a[i];
		}else{
			break;
		}
	}if(sum > ans) return sum;
	else return -1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i <= n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	int l = 1,r = n;
	while(l < r){
		int mid = (l+r)/2;
		int x = f(mid);
		if(x == -1){
			r = mid;
		}else{
			ans = x;
			l=mid+1;
		}
	}cout << ans;
	return 0;
}