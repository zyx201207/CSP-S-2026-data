#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],maxx,i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int mid = (1 + n) / 2;
	for (i = 1;i <= n; i++){
		if (a[mid] - a[i] < 0){
			break;
		}
		s[i] = a[mid] - a[i];
	}
	sort(s + 1,s + i);	
	int j;
	for (j = 1;j < i;j++){	
		m -= s[j];
		if (m < 0){
			break;
		}
	}
	cout << j - 1;
}
