#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=5e5+7;
int a[N],s[N];
inline int calc(int l,int r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int res=0;
	for(int i=1,j=1;i<=n;i++){
    	while(j<=n&&calc(i,j)<=m)j++;
    	if(i<j&&calc(i,j-1)<=m)res=max(res,j-i);
	}
	cout<<res;
}
