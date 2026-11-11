#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N];
bool get(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*(x)-(b[i]-b[i-x])<=m){
			//cout<<i-x+1<<" "<<i<<" "<<a[x]*i-(b[i]-b[i-x])<<endl;
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<i<<" "<<j<<" "<<a[j]*(j-i+1)-(b[j]-b[i-1])<<endl;
		}
	}
	*/
	int l=1,r=n;
	while(l!=r){
		int mid=((l+r)>>1)+1;
		//cout<<l<<" "<<r<<endl;
		if(get(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
		//cout<<l<<" "<<r<<endl;
	}
	cout<<l<<endl;
	return 0;
}
