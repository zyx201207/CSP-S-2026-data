#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	z=a[1];
	if(m==1){
		cout<<a[n];
	}if(m==n){
		for(int i=2;i<=n;i++){
			z=z&a[i];
		}
		cout<<z;
	}
	return 0;
}
