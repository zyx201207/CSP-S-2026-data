#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	long long a[100000005],maxn=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);}
	if(m==1)
		cout << 0;
	else cout << maxn;
	return 0;
}
