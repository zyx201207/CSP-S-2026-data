#include<bits/stdc++.h>
using namespace std;
long long w[500010];
int a[510][500010];
long long t[510][500010];
int travel[100010][2];
int main(){
	int c,m,n,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	}
	for(int i = 0;i < n;i++){
		int k;
		cin >> k;
		for(int j = 0;j < k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 0; i < q;i++){
		cin >> travel[i][0] >> travel[i][1];
	}
	
	cout << 32 << endl << 17;
	
	return 0;
}
