#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N];
bool check(int j){
	int res = 0;
	for(int i=1;i<j;++i){
		res += a[j]-a[i];
	}
	if(res<=m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l = 1,r = n;
	while(r>l){
		int mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout<<l;
	return 0;
}
