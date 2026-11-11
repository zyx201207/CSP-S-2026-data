#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);s
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i] >> c[i];
	}
	int l=0,r=n-1,lp=0,rp=0;
	while(!(l>=r&&lp>=rp)){
		int Min=min(a[l]-lp,a[r]-rp);
		lp+=Min;
		rp+=Min;
		if(c[l]!=c[r]){
			cnt+=Min;
		}
		if(lp==a[l]){
			l++;
			lp=0;
		}
		if(rp==a[r]){
			r--;
			rp=0;
		}
	}
	cout << cnt;
}
