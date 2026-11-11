#include<bits/stdc++.h>
using namespace std;
#define ll long long  
const int N=500005;
ll a[N],b[N],c[N],n,cnt,m,i;
bool check(int x,int y);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=n-1;i>=0;i--){
		a[i]=a[i]-a[i-1];
	}//差分 
	a[0]=0;
	for(i=n-1;i>=0;i--){
		b[i]=b[i+1]+a[i];
		c[i]=c[i+1]+b[i];
	}//前缀和 
	i=n-1;
	while(--i){
		int l=1,r=i;
		while(l!=r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}//二分答案 
		if(check(r,i)){
			cnt=max(1ll*i-r+2,cnt);
//			cout<<cnt<<" ";
		}
//		cout<<i<<endl;
	}
	cout<<cnt;
	return 0;
}
bool check(int x,int y){
	if(c[x]-(c[y+1]+(y-x+1)*b[y+1])>m){
		return 0;
	}
	else return 1;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

ｂ(￣▽￣)ｄ 
*/
