#include<bits/stdc++.h>
using namespace std;
long long x[2000001], a[2000001], l[2000001], r[2000001];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d %d", &c, &t);
	for(int i = 0; i < t; i++){
		int n;
		long long d;
		scanf("%d %lld", &n, &d);
		for(int j = 0; j < n; j++){
			cin>>x[j];
			if(j)a[j] = x[j]-x[j-1];
		}
		for(int j = 0; j < n; j++){
			int s = 0, k;
			for(k = j+1; k < n; k++){
				if(s+a[k]>d)break;
				s += a[k];
			}
			r[j] = k-1;
			s = 0;
			for(k = j-1; k >= 0; k--){
				if(s+a[k+1]>d)break;
				s += a[k+1];
			}
			l[j] = k+1;
		}
		int c = 0;
		for(int j = 0; j < n; j++){
			for(int k = j+1; k < n; k++){
				if(l[j]<l[k]&&l[k]-l[j]<3&&l[k]<r[j]&&r[j]-l[k]<3&&r[j]<r[k]&&r[k]-r[j]<3&&l[k]>j&&r[j]<k)c++;
			}
		}
		for(int j = 0; j < n; j++){
			cout<<l[j]<<" "<<r[j]<<endl;
		}
		printf("%d\n", c);
	}
	return 0;
}
