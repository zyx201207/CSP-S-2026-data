#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],h;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		if(b[i]>m){
			cout<<i-1;
			break;
		}
	}
	return 0;
}
