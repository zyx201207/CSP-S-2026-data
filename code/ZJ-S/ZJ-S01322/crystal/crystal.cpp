#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m;
int a[N],b[N];
int ans;

void check(int x,int end) {
	int res=0,pos=0;
	for(int i=1; i<=end; i++) b[i]=x-a[i];
	sort(b+1,b+end+1);
	for(int i=1; i<=end; i++){
		res+=b[i];
		pos++;
		if(res>m)break;
	}
	if(res>m)pos--;
	ans=max(ans,pos);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1) {
		cout<<1;
		return 0;
	}
	for(int i=n; i>=2; i--){
		check(a[i],i);
		if(ans>=i)break;
	}
	cout<<ans;
	return 0;
}
//神兽保佑，代码无bug!!!

