#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn],b[maxn];
int cnt = 0;

void f(int x) {
	cnt = 0;
	for (int k = x; k >= 1; k/=2) {
		
		a[cnt++] = k % 2;
	}
	a[cnt]=1;
}

void ff(int x) {
	cnt = 0;
	for (int k = x; k >= 1; k/=2) {
		
		a[cnt++] &= k % 2;
	}
	a[cnt]=1;
}


int main() {

	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);

	cin >> n>>m;
	cin>>a[0];
	f(a[0]);
	for(int i=1;i<n;i++){
		cin>>a[i];	
	}
	int sum=0;
	int maxx=-1;
	for(int i=0;i<n;i++){
		for(int j=i;j<m+i;j++){
			ff(a[j]);
		}
		for(int j=0;j<cnt;j++){
			b[j]=a[j];
			a[j]=0;
		}
		for(int j=0;j<cnt;j++){
			sum+=(b[j]*=pow(2,j));
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
}
