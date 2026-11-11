#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],l,r,an,s[N];
bool ch(int x){
	for(int i=x;i<=n;i++){
		int no=a[i]*x-(s[i]-s[i-x]);
		if(no<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m,l=1,r=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	while(l<=r){
		int mi=(l+r)>>1;
		if(ch(mi))an=mi,l=mi+1;
		else r=mi-1;
	}
	cout<<an;
	return 0;
}