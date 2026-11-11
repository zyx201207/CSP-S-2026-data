#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0;
long long a[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int j=1;j<=q;j++){
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
