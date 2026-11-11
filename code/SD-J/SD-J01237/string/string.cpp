#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans;
char c[200010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0,r=a[n],i=0,j=n;
	while(i<j){
		if(l<r){
			if(c[i+1]!=c[j]){
				if(l+a[i+1]<=r){
					ans+=a[i+1];
				}
				else ans+=r-l;
			}
			l+=a[++i];
		}
		else{
			if(c[i]!=c[j-1]){
				if(r+a[j-1]<=l){
					ans+=a[j-1];
				}
				else ans+=l-r;
			}
			r+=a[--j];
		}
	}
	cout<<ans;
	return 0;
}
/*
纯模拟 

9:25 T2对拍完成 
*/
