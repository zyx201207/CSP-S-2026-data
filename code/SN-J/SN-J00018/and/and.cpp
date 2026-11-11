#include<bits/stdc++.h>
using namespace std;
int n,m,maxn = 0;
long long a[200005];
/*string e(long long x){
	long long h;
	string s;
	while(n > 0){
		h = x % 2;
		x /= 2;
		s += char(h - '0');
	}
	return s;
}
int q(string x,string y){
	long long z[500005],b[500005],k = 0,sum = 1,ans = 0;
	for(int i = 0;i < max(x.size(),y.size());i++){
		if(int(x[i] - 0) + int(y[i] - 0) == 0 ||int(x[i] - 0) + int(y[i] - 0) == 2){
			z[++k] = 1;
			b[k] = i;
		}
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= b[i];j++) sum *= 2;
		ans += sum;
	}
	return ans;
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	/*long long e = a[n];
	for(int i = n - m + 1;i < m;i++){
		e ^= a[n - m];
	}*/
	cout << a[n - m + 1];
	/*for(int i = 1;i <= n - m + 1;i++){
		for(int j = i + 1;j <= n - m + 1;j++){
			
		}
	}*/
	return 0;
}


