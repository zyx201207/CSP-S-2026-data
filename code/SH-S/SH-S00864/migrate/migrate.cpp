#include <bits/stdc++.h>
using namespace std;
long long a[2000100],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long s=d/(a[2]-a[1]);
		if(s==2){
			if(n>=4)cout << n-3;
			else cout << 0;
		}
		else cout << 0;
		cout << n;
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
