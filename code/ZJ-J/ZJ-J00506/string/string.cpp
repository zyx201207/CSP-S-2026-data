#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
int a[N];
ll ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int cntl=0,cntr=0;
	int l=0,r=n+1;
	while(l<r){
		if(!cntl) cntl=a[++l];
		if(!cntr) cntr=a[--r];
		if(l>=r) break;
		if(c[l]!=c[r]) ans+=min(cntl,cntr);
		if(cntl<cntr){
			cntr-=cntl;
			cntl=0;
		}
		else{
			cntl-=cntr;
			cntr=0;
		}
	}
	cout<<ans;
	return 0;
}
