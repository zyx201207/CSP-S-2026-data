#include<bits/stdc++.h>
using namespace std;
long long int n,m,sum,a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2 ; i<=m ; i++){
		sum=sum&a[i];
	}
	cout << sum;
	return 0;
}
