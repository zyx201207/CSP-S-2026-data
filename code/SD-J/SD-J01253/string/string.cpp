#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char c[200010]; 
int l,r,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(c[l]==c[r]){
			int jian=min(a[l],a[r]);
			a[l]-=jian;
			a[r]-=jian;
		}else{
			int jian=min(a[l],a[r]);
			a[l]-=jian;
			a[r]-=jian;
			ans+=jian;
		}
		if(!a[l]){
			l++;
		}
		if(!a[r]){
			r--;
		}
	}
	cout<<ans;
	return 0;
}

