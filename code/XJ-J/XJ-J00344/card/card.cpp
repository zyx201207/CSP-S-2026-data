#include<bits/stdc++.h>
using namespace std;
int n = 0;
int m = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	const int l = n-1;
	int a[l];
	for(int i = 0;i <= l;i++){
		cin >> a[i];
	}
	cout << m << " " << a[0] << " " << n;
    return 0;
}