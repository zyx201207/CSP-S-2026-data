#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N];
inline int check(int l,int r){
	int len=r-l;
	int t=a[r]*len-(sum[r-1]-sum[l-1]);
	return (t<=m);
}
int func(int x){
	int l=1,r=x,t;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid,x)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	t=l;
	return (x-t);
}
signed main(){
	//freopen("xxx.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j,mx=-1;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1,[](int x,int y){
		return x<y;
	});
	for(i=1;i<=n;i++){
		int t=func(i);
		mx=max(mx,t);
	} 
	cout<<mx+1;
	return 0;
} 