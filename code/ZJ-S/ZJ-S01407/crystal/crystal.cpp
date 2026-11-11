#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
bool check(int x){
//		cout<<x<<": ";
	long long mx=a[x],cnt=0;
	L(j,1,x){
		cnt+=mx-a[j];
	}
	if(cnt<=m) return 1;
	L(i,x+1,n){
		cnt=cnt-(a[i-1]-a[i-x])+(x-1)*(a[i]-a[i-1]);
//		if(i>10000)cout<<i<<" ";
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	L(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
//		cout<<mid<<" ";
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
//		cout<<l<<" "<<r<<" ";
	}
	cout<<l;
	return 0;
}