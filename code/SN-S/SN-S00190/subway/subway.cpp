#include<bits/stdc++.h>
using namespace std;
struct f {
	int t,z,zt,sl;
} a[505];
int c,n,m,d,p,w1,w2,sum,b[25],x,y,q = 1;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m ; i++) {
		cin >> a[i].t;
	}
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i].sl;
		for(int j = 1; j <= a[i].sl; j++) {
			cin >> a[i].z >> a[i].zt;
		}
	}
	for(int i = 1; i <= a[1].sl ; i++) {
		int j = 2;
		for(int k = 1; k <= a[j].sl ; k++) {
			if(a[i].z == a[k].z) {
				b[q] = a[i].z;
				q++;
			}
		}
		j++;
	}
	for(int q = 1; q <= p; q++) {
		cin >> x >> y;
		sum = a[x].t + a[y].t + a[x].zt + a[y].zt;
		for(int i = 1; i <= m ; i++) {
			if(a[i].z == b[i]) {
				sum += a[b[i]].zt ;

			}
		}
		cout << sum	<<endl;
	}

	return 0;
}
