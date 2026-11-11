#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
long long a[N],n,k,mx = -1;
void f(long long ans,long long now,long long i){
	if(i == 0){
		mx = max(mx,ans);
		return ;
	}
	for(int j = now + 1;j <= n - i + 1;j++){
		f(ans & a[j],j,i - 1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(long long i = 1;i <= n - k + 1;i++){
		f(a[i],i,k - 1);
	}
	cout << mx;
	return 0;
}
