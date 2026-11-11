#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
int n;
i64 m,a[N],c[N];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(a[i]*mid-(c[i]-c[i-mid])<=m){
			return true;
		}
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	int low=0,high=n;
	while(low<high){
		int mid=(high+low+1)>>1;
		if(check(mid)){
			low=mid;
		}
		else{
			high=mid-1;
		}
	}
	cout<<low;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
