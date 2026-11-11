#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,s,a[N],d1[N],d2[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d1[i-1]=a[i]-a[i-1];
	}
	for(int i=n-1;i>0;i--){
		d1[i]=d1[i+1]+d1[i];
	}
	for(int i=n-1;i>0;i--){
		d2[i]=d2[i+1]+d1[i];
	}
//	for(int i=1;i<n;i++){
//		cout<<d1[i]<<" ";
//	}cout<<'\n';
//	for(int i=1;i<n;i++){
//		cout<<d2[i]<<" ";
//	}cout<<'\n';
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(d2[mid]-d2[i]-(i-mid)*d1[i]>m)l=mid+1;
			else r=mid;
		}s=max(s,i-l+1);
	}cout<<s;
	return 0;
}/*
1 2 4 1
8 7 5 1
21 13 6 1
2 3 0 5

*/
