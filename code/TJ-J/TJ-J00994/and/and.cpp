#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[100005];
    for(int i=0;i<n;i++){
    	cin >> a[i];
	}
	sort(a,a+n);
	int b=a[0] and a[1];
	for(int i=2;i<m;i++){
		b=b and a[i];
	}
	cout << b;
    return 0;
}

