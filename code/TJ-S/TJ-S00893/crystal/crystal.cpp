#include<bits/stdc++.h>
using namespace std;
long long m; 
long long n,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=abs(a[i]-a[i-1])*(i-1)+b[i-2];
	}
	for(int i=2;i<=n;i++){
		if(m<b[i]){
			cout<<i;
			return 0;
		}
	} 
	cout<<n;
	return 0;
} 
