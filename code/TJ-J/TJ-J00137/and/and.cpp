#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans,b[100],c[2][200100];
int check(long long n){
	while(n){
		if(n%2 == 0)return false;
		n /= 2;
	}
	return true;
}
int cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f = 1,flag = 1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[0][i] = a[i];
		if(!check(a[i]))f = 0;
		if(a[i] != i-1)flag = 0;
	}
	if(f == 1){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	else if(m == 1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	else if(m == n){
		ans = a[1];
		for(long long i = 2;i<=n;i++){
			ans = ans & a[i];
		}
		cout<<ans;
	}
	else if(m == 2){
		for(long long i=1;i<=n;i++){
			for(long long j = i+1;j<=n;j++){
				ans = max(ans,a[j] & a[i]);
			}
		}
		cout<<ans;
	}
	else if(flag == 1){
		sort(a+1,a+1+n,cmp);
		ans = a[1];
		for(long long i=1;i<=m;i++){
			ans = ans & a[i];
		}
		cout<<ans;
	}
	else{
		f = 0;
		flag = 0;
	}
	return 0;
}
