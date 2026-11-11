#include<bits/stdc++.h>
#define int int
using namespace std;
const int N = 5e5 + 5;
int n, m, ans;
long long a[N], u[N], su;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)	
		cin>>a[i];
	sort(a + 1, a + 1 + n);
	int j = 1;
	for(int i = 1; i <= n; i++){
		u[i] = u[i-1] + (a[i]-a[i-1]) * (i-1);
//		su += (a[i]-a[i-1]) * (i-j);
		while(u[i]-u[j]-(j-1)*(a[i]-a[j]) > m){
			j++;
//			su -= (a[j]-a[j-1]) * (j-1);
		}
		ans = max(ans, i-j+1);
//		cout<<i<<" "<<j<<" "<<u[i]-u[j]-(j-1)*(a[i]-a[j])<<"\n";
	} 
//	cout<<u[ans]<<" "<<u[ans-1]<<"\n";
	cout<<ans;
	return 0;
}