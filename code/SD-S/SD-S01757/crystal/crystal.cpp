#include<iostream>
#include<algorithm>
using namespace std;
const int N=500005;
int n,m; 
long long a[N];
long long s[N];
bool check(int l,int r){
	if(((r-l+1)*a[r]-s[r]+s[l-1])<=m)return true;
	return false;
}
int rf(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid,x))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,i-rf(i)+1);
	}
	cout<<maxx;
	return 0;
}
