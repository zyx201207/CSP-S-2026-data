#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],qc[500002],maxx=0,id,idd;
int Find(long long x){
	int l=x,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if((a[mid]*(mid-x)-qc[mid-1]+qc[x-1])>m)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qc[i]=qc[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long x=Find(i)-1;
		if(maxx<(x-i+1)){
			maxx=x-i+1;
//			id=i;
//			idd=x;
		}
	}
	cout<<maxx;
	return 0;
}
