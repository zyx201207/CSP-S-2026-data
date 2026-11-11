#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],ans;
struct node{
	int pos1,pos2,op;
}s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ans=1;
	while(m){
		sort(a+1,a+n+1);
		if((a[2]-a[1])>m) break;
		m-=(a[2]-a[1]);
		++ans;
		a[1]=1e9+10;
		a[2]+=a[1];
	}
	if(ans==1) ans=0;
	cout<<ans;
	return 0;
}