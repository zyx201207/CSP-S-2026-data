#include<bits/stdc++.h>
using namespace std;
long long n,s;
long long a[10000005];
long long maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]&a[i+1]);
		a[i]=maxx;
	}
	cout<<maxx;
	return 0;
}
