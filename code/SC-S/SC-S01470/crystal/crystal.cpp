#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a[500010];
int n,m;
bool check(int x){
	int cnt=m;
	for(int i=1;i<x;i++){
		cnt+=a[i];
	}
	for(int i=1;i+x-1<=n;i++){
		cnt-=a[i-1];
		cnt+=a[i+x-1];
		//cout<<i<<" "<<cnt<<" "<<x<<endl;
		if(cnt>=a[i+x-1]*x) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	} 
	cout<<l;
	return 0;
}
/*
5 5
1 2 4 8 9
*/