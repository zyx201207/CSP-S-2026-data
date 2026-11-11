#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and4.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	cout << a[n / 2];
	return 0;
}
