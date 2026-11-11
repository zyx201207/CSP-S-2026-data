#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,a[100005];
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		if(a[i]>m)
			cout<<a[i];
	}
	return 0;
}
