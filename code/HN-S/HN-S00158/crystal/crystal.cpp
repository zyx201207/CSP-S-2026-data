#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[50005];
int left(int x){
	int cnt=0;
	for(int i=x-1;i>=0;i--){
		if(x-a[i]<m){
			cnt++;
			m-=x-a[i];
		}
		else return cnt;
	}
	return 0;
}
int right(int x){
	int cnt=0;
	for(int i=x;i<n;i++){
		if(a[i]-x<=m){
			cnt++;
			m-=a[i]-x;
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int maxx=-114514;
	for(int i=0;i<n;i++) {
		int cnt=left(a[i])+right(a[i]);
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
} 
