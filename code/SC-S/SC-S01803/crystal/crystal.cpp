#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[500005],zh[500005],n,m;
bool cmp(ll c_a,ll c_b){
	return c_a<c_b;
}
ll rezh(int l,int r){
	return zh[r]-zh[l]-(a[r]-a[l])*(l-1);
}
int find(int l,int r,int s){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(rezh(s,mid+1)==m) return mid+1;
	else if(rezh(s,mid+1)>m) return find(l,mid,s);
	return find(mid+1,r,s);
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a,a+n,cmp);
	for(int i=2;i<=n;i++){
		zh[i]=zh[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int Max=0;
	for(int i=1;i<n;i++){
		Max=max(Max,find(i+1,n,i)-i+1);
	}
	cout<<Max;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*


*/