#include <bits/stdc++.h> 
using namespace std;
int m,n,ma;
long long a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cout<<n<<m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		ma=max(a[i]^a[i+1],a[i]^a[i-1]);
	}
	cout<<ma;
	return 0;
}
