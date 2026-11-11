#include<bits/stdc++.h>
using namespace std;
int n,x;
long long m,ans;
long long a[5000010];
bool f = true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] != a[i-1] && i != 0) f = false;
	}
	if(f){
		if(m%2 == 0 || m == n){
			cout<<m;
			return 0;
		}else{
			cout<<m-1;
			return 0;
		}
	} 
	sort(a,a+n);
	long long s = a[n/2];
	for(long long k = 1;k <= m;k++){
		if(a[x] == s) x+=1;
		a[x]+=1;
	}
	for(int i = 0;i < n;i++){
		if(a[i] == s) ans++;
	}
	cout<<ans;
	return 0;
}
