#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=2e5+5;
int n,ans,lst;
struct node{
	int l,r,a;
	char c;
}p[mx];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		p[i]={p[i-1].r+1,p[i-1].r+a,a,c};
	}
	lst=n;
	int mid=ceil((p[n].r+1)/2);
	for(int i=1;i<=n;i++){
		if(p[i].l>=mid)break;
		int ndr=p[n].r-p[i].l+1,ndl=p[n].r-min(p[i].r,mid)+1;
		while(p[lst].r>=ndl){
			if(p[lst].c!=p[i].c)
				ans+=(min(ndr,p[lst].r)-max(ndl,p[lst].l)+1);
			lst--;
		}
		if(p[lst].r<ndl-1)lst++;
	}
	cout<<ans;
	return 0;
}
