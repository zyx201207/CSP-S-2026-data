#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[200007];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	for(int i=2;i<=n;i++){
		a[i]=a[i] & a[i-1];
	}
	ans=a[m-1];
	cout << ans;
}