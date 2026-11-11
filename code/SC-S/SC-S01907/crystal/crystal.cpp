#include <bits/stdc++.h>
using namespace std;

long long n,m,t=1;
long long a[100100],b[100100];

int main(){
//	freopen("crystal.in","w",stdin);
//	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t=(a[i]-a[i-1]);
		b[i]=t+b[i-1];
	}
	for(int i=1;i<=n;i++){
		if(m<b[i]){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
