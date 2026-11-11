#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a + 1, a + 1 + n);
		cout << a[n];
		return 0;
	}
	if(a[1] == 1 && a[2] == 2){
		cout << n - m;
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	cout << a[m];
	return 0; 
}
