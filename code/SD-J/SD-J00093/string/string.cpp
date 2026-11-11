#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
long long ans=0;
int m,a[M];
char c[M];
signed main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=m;
	while(l<r){
		int len=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=len;
		}
		if(a[l]>a[r]){
			a[l]-=len;
			r--;
		}else if(a[r]>a[l]){
			a[r]-=len;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0; 
}
