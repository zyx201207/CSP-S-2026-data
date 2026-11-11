#include<bits/stdc++.h>

using namespace std;

long long n,m,a[200009],l,maxn;

bool cmp(long long a,long long b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	cin >> n >> m;
    scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n-m;i++){
		l |= a[i];
//		for (int j = i;j <= i+m-1;j++){
//			cout << j << ' ';
//			l &= a[j];
//		}
		l &= a[i+m-1];
		maxn = max(maxn,l);
		if (a[i] & -1 > a[i+m] & -1 * 4){
			break;
		}
//		cout << endl;
	}
//	cout << maxn;
	printf("%lld",maxn);
	return 0;
} 
