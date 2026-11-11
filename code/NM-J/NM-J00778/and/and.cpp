#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,s,a[100005];
	cin >> n;
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n-1);
	unique(a,a+n-1);
	cout << a[n-3];
	return 0;
}
