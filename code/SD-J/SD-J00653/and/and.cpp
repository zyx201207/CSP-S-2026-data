#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
int pl[N];
int n,m,ans=0;
void Ans(int q,int l){
	if(l==0){
		int nans=a[pl[1]];
		for(int i=2;i<=m;++i){
			nans&=a[pl[i]];
		}
		ans=max(ans,nans);
		return;
	}
	for(int i=q+1;i<=n-l+1;++i){
		pl[l]=i;
		Ans(i,l-1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	Ans(0,m);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
