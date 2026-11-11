#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[1000000];

bool cmp(int x, int y){
	return x>y;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	sort(a, a+n, cmp);
	
	cout<<a[m-1];
	
	return 0;
} 
