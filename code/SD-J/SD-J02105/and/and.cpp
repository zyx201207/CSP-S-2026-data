#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long s=a[i];
			s&=a[j];
			ma=max(ma,s);
		}
	}
	cout<<ma;
	return 0;
}
