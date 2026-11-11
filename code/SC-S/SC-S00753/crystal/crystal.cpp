#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500005],h[500005]={0};
long long cost(int x,int y){
	if(x>y) swap(x,y);
	if(x==y) return 0;
	else return a[y]*(y-x)-(h[y-1]-h[x-1]);
}
int find(int x){
	int l=1,r=x,mid;
	while(l<=r){
		mid=(l+r)/2;
		long long pay=cost(mid,x);
		if(pay==m) return mid;
		else if(pay>m) l=mid+1;
		else r=mid-1;
	}
    return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) h[i]=h[i-1]+a[i];
	for(int i=2;i<=n;i++){
		ans=max(ans,i-find(i)+1);
	}
	cout<<ans;
	return 0;
}