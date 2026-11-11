#include<bits/stdc++.h>
using namespace std;

long long h,n,m;
int a[200010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	sort(a + 1,a + n + 1);
	h = a[n];
	for(int i = n - 1;i >= n - m + 1;i--){
		h &= a[i];
	}
	
	cout<<h;
	return 0;
}
