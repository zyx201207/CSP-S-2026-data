#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=500005;
int n,m,a[N];

bool check(int x){
	int r=x-1,ans=0;
	for(int i=0;i<n-x+1;i++){
		ans=0;
		for(int j=i;j<i+r;j++){
			ans+=a[i+r]-a[j];
		}
		if(ans<=m){
			return 1;
		}
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);


	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	
//	cout << check(4416);
	
	int l=2,r=N,mid,ans=-1;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			ans=mid;
			r=mid;
		}
//		printf("check=%d mid=%d l=%d r=%d\n",check(mid),mid,l,r);
	}
	cout << ans;
	
	
	return 0;
}
/*
5 6
1  2  15 17  19
1  13 2  2
27 17 6
33 23
41


5 6
1 2 15 17 19


1 2 3 4 5
1 1 1 0 0
*/
