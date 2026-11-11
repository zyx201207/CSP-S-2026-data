#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200020],maxn,s[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];	
	}
		for(int i=1;i<=n;i++){
			s[i] = a[i]&a[i+1];
		}
		for(int j=1;j<=n;j++){
			maxn = max(s[j],maxn);
		}
		cout << maxn;
	/*else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				s[i] = a[i]&a[i+j];
			}
		}
		sort(s+1,s+1+n);
		for(int x=1;x<=n;x++){
			maxn = max(s[x],maxn);
		}
		cout << maxn;
	}*/
	return 0;
}