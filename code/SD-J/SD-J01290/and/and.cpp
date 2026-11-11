#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[200005];
int cnt(int n){
	int a=0;
	while(n){
		a+=n%2;
		n/=2;
	}
	return a;
}
bool cmp(int a,int b){
	int ac=cnt(a),bc=cnt(b);
	if(ac==bc) return a>b;
	else return ac>bc;
}
signed main(){
	freopen("and4.in","r",stdin);
	freopen("and4.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}

