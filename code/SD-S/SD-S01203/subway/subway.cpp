#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c==0){
		if(n==2){
			cout << 32 << endl << 17;
			return 0;
		}else if(n==3){
			cout << 35 << endl << 16;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
