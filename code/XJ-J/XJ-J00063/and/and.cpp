#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=n-m+1;i>=1;i--){
	int cnt=0;
	for(int j=i+1;j<=n;j++){
		if( (a[j] & a[i])>=a[i] )cnt++;
	}
	if(cnt>=m-1){
		cout<<a[i];
		return 0;
	}
}
cout<<0;
return 0;
} 
