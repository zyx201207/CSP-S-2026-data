#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[20010],b[20010];
long long s = INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	for(int i = 1;i <= m;++i){
		b[i] = i;
	}
	for(int i = 1;i <= n;++i){
		if(s < a[i] & a[i - 1]) s = a[i] & a[i - 1];
	}
	cout << s;
	return 0;
}
