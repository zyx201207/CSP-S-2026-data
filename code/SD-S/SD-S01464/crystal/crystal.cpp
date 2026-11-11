#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i;
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(abs(sum[i]-(a[i]*i))>m){
			break;
		}
	}
	cout<<i-1<<endl;

	return 0;
}
//5 5 1 2 4 8 9
//3845 315275
//3832 315248
//13      27
