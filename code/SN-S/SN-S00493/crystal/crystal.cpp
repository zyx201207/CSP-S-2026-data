//SN-S00493
//程思阳
//西安市铁一中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],re;
int cn(int i,int j){
	return a[j]*(j-i+1)-s[j]+s[i-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		if(j<i) j=i;
		while(j<n&&cn(i,j+1)) j++;
		re=max(re,j-i+1);
	}
	cout<<re<<endl;
}
