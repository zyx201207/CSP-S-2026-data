#include <bits/stdc++.h>
using namespace std;
int a[500100],n,m,ans=0,mid,l,r,zc;
int lmq(int x,int y){
	int c=0,b[500100],s=0;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		if(x-a[i]<0){
			c=i-1;
			break;
		}
        b[i]=x-a[i];
	}
	for(int i=c;i>=1;i--){
		if(y>=b[i]){
			y=y-b[i];
			s++;
		}
	}
	return s;   
}
int zzc(){
	int s=a[2]-a[1];
	for(int i=2;i<=n-1;i++){
		if(a[i+1]-a[i]!=s){
			return 0;
		}
	}
	return s;
}
int hcy(int x,int y){
	if(y/x<n){
		return y/x;
	}
	else{
		return n;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	zc=zzc();
	if(zc){
		cout<<hcy(zc,m);
		return 0;
	}
	for(int i=a[1];i<=a[n];i++){
		ans=max(ans,lmq(a[i],m));
	}
//	l=a[1];
//	r=a[n];
//	while(l<=r){
//		mid=(l+r)/2;
//		if(ans<lmq(mid,n)){
//			ans=lmq(mid,n);
//			l=mid+1;
//		}
//		else{
//			r=mid-1;
//		}
//	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/