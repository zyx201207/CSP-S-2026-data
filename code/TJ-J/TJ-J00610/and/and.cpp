#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int maxn=-0x3f3f3f3f;
int a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		sort(a,a+n+1);
		cout << a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
		for(int k=i+1;k<=n;k++){
			maxn=max(a[i]&a[k],maxn);
		}
	}
	} 
	cout << maxn;
	return 0;
}
