#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
unsigned long long m;
long long a[N],v[N];
int fun(int x,int y){
	int mid,l=x,r=y;
	unsigned long long ull;
	while(l<=r){
		mid=(l+r)/2;
		ull=(a[y])*(y-mid+1)-(v[y]-v[mid-1]);
		if(ull<=m) r=mid-1;
		else l=mid+1;
	}if(ull>m) mid++;
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) v[i]=v[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,i-fun(1,i)+1);
	}cout<<ans;
	
	return 0;
}