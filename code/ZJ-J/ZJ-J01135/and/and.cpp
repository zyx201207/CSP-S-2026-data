#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,t,s,a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    t=1;s=a[n];
    for(i=n-1;i>=1;i--){
    	t++;s=s&a[i];
    	if(t==m){
    		cout<<s;return 0;
		}
	}
}
