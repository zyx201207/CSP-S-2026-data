#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int c,t,i,j,n,d,x;
	cin >> c >> t;
	for(i=0;i<t;i++){
		cin >> n >> d;
		int a[n];
		for(j=0;j<2;j++){
			cin >> a[j];
		}
		for(j=2;j<n;j++){
			cin >> x;
		}
		cout << (n<d/(a[1]-a[0])*2-1? 0: n-(d/(a[1]-a[0])*2-1)) << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
