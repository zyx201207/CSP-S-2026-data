#include<bits/stdc++.h>
using namespace std;
int n = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	const int l = n-1;
	int a[l];
	string a1[l];
	for(int i = 0;i <= l;i++){
		cin >> a[i];
		cin >> a1[i];
	}
	cout << a[l];
    return 0;
}