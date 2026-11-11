#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N],pre[N];
bool check(int s){
	for(int i=s;i<=n;i++){
		long long sum=a[i]*s;
		int l=i-s+1,r=i;
		long long Sum=pre[r]-pre[l-1];
		if(sum-Sum<=m)return 1;
	}
	return 0;
}
int find(int l,int r){
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	cout<<find(1,n+1);
	return 0;
}

