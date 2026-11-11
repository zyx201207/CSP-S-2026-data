#include<bits/stdc++.h>
using namespace std;
long long  n,m,cnt,a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		cnt=a[0];
		for(int i=1;i<n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	sort(a,a+n,cmp);
	long long maxx=0;
	for(int i=0;i<=n-m-1;i++){
		maxx=a[i];
		for(int j=i+1;j<=m+i-1;j++){
			maxx=maxx&a[j];
		}
		cnt=max(cnt,maxx);
	}
	cout<<cnt;
	return 0;
}
