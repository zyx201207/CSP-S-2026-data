#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],q[500005];
bool cmp(long long a,long long b){
	return a>b;
}
long long need(long long le,long long ri){
	return a[ri]*(ri-le+1)-(q[ri]-q[le-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long fs=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]<0){
			fs=min(fs,a[i]);
		}
	}
	for (int i=1;i<=n;i++){
		a[i]-=fs;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	long long left=1;
	long long right=1;
	long long nowm=0;
	while (true){
		while (need(left,right+1)<=m&&right<=n) right++;
		nowm=max(nowm,right-left+1);
		left++;
		if (right>n||left>n){
			break;
		}
	}
	cout<<nowm;
	return 0;
}
