#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,ans;
int a[N];
void p(int s,int cnt,int lst){
	if(s==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=lst+1;i<=n;i++){
		p(s+1,cnt&a[i],i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++) p(1,a[i],i);
	cout<<ans;
	return 0;
}

