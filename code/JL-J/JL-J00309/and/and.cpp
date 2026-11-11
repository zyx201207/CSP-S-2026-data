#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	m=n/2;
	cout<<a[m];
    return 0;
}
