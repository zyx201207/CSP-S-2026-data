#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],l,r,mid;
bool pd(){
	long long h=0;
	for(int i=1;i<mid;i++){
		h+=a[mid]-a[i];
		if(h>m)return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=1;r=n;
	while(l<=r){
		mid=(r-l)/2+l;
		if(pd()){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
} 