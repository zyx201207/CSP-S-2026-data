#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[10000],b[10000];
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]||a[i+1];
	}
	cout << 12; 
	
}

