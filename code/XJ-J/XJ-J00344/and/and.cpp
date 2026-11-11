#include<bits/stdc++.h>
using namespace std;
int n = 0;
int m = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	const int l = n-1;
	int a[l];
	for(int i = 0;i <= l;i++){
		cin >> a[i];
	}
	cout << a[l];
    return 0;
}