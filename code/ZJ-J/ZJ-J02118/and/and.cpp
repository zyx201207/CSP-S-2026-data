#include<bits/stdc++.h>
using namespace std;
int a[200001];

bool cmp(int a,int b) {
	return a>b;
	return 0;
}

bool ms(int a){
	int i=2;
	while(i<a){
		i*=2;
	}
	return(a==i);
	return 0;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,f2=0;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i]!=i-1) {
			f2=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(f2==0) {
		for(int i=1;i<=n;i++){
			if(ms(a[i])){
				a[i]=0;
			}
		}
		sort(a+1,a+n+1,cmp);
		int sum=a[1];
		for(int i=2; i<=m; i++) {
			sum=sum&a[i];
		}
		cout << sum;
		return 0;
	}
	cout << a[m];
	return 0;
}

