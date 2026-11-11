#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N];
int s[N];
bool chk(int x){
	for(int i = x;i<=n;i++){
		int k = a[i]*x;
		int t = k-(s[i]-s[i-x]);
		if(t<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		s[i] = s[i-1]+a[i];
	}
	int l = 1,r = n;
	while(l<r){
		int mid = l+r+1>>1;
		if(chk(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout<<l<<endl;
    return 0;
}
