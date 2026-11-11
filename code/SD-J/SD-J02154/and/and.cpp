#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m;
int maxx=0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout << maxx;
		return 0;
	}
	maxx=0;
	if(m==2){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++) {
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout <<maxx;
	}
	return 0;
}
