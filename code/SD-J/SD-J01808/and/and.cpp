#include<bits/stdc++.h>
using namespace std;
int a[300000];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,ans=0;
	cin >> n >> m;
	for (long long i=1;i<=n;++i){
		cin >> a[i];
	} 
	sort(a+1,a+1+n,cmp);
	for (int long long j=1;j<=n-m+1;++j){
		for (long long i=j;i<=j+m-1;++i){
			
			if (i==j) {
				ans=a[i];
				continue;
			}
			ans=ans&a[i];
		}
		if (ans!=0) {
			break;
		}
	}
	cout << ans;
	return 0;
} 
