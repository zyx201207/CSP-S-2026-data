#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
int k=0,sum=0;
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m+1;++i){
		int k=a[i];
		for(int j=1;j<=m-1;++j){
			if(k%a[i+j]!=0){
				k=a[i+j];
			}
			else{
				break;
			}	
		}
		sum=max(sum,k);
	}
	cout << sum;
	return 0;
}
