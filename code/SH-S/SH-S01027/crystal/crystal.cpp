#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005],d[500005];
bool check(int x,long long t){
	for(int i=x;i<=n;i++){
		if(((x-1)*a[i]-d[i-1]+d[i-x])<=t)return true;
	}
	return false;	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(check(mid,m)==true){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout << l <<endl;
	return 0;
}
