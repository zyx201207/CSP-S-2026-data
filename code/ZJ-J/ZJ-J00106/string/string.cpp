#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],ans,n;
char c[N];
int l,r,lt,rt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<r){
		if(a[l]-lt>a[r]-rt){
			if(c[l]!=c[r]){
				ans+=(a[r]-rt);
			}
			lt+=(a[r]-rt);
			r--;rt=0;
		}else if(a[l]-lt==a[r]-rt){
			if(c[l]!=c[r]){
				ans+=(a[r]-rt);
			}
			l++;lt=0;
			r--,rt=0;
		}else if(a[l]-lt<a[r]-rt){
			if(c[l]!=c[r]){
				ans+=(a[l]-lt);
			}
			rt+=(a[l]-lt);
			l++,lt=0;
		}
	}
	cout<<ans;
	return 0;
}