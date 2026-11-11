#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600999];
int pick(int mid){
	int need=0,md;
	for(int i=1;i<=mid;i++){
		need+=a[mid]-a[i];
	}
	md=need;
	for(int i=mid+1;i<=n;i++){
		need+=mid*(a[i]-a[i-1]);
		need-=a[i]-a[i-mid];
		md=min(need,md);
	}
	if(md>m) return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int r=n,l=1;
	while(r>l){
		int mid=(l+r+1)/2;
		if(pick(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
}
