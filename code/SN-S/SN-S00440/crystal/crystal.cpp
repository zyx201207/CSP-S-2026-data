#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500007],ans,b[500007],xx;
bool amp(long long x,long long y){
	return x<y;
}
long long tf(int x){
	long long l=1,r=x,mid=(l+r)/2;
	while(l!=r){
		if(a[x]*(x-mid+1)<=b[x]-b[mid-1]+m) r=mid;
		else l=mid+1;
		mid=(l+r)/2;
	}
	return x-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,amp);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		ans=max(tf(i),ans);
	}
	cout<<ans;
	return 0;
}
//yl1
//8 6
//4 1 1 3 3 1 1 3 

