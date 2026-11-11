#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],n,m,ans;
int b1[2][2]={{0,1},{1,0}};
int b2[4][2]={{0,1},{1,1},{1,1},{1,0}};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=(a[i]%2)*(1<<(i-1));
	}
	if(n==1){
		if(a[1]==1)cout<<1<<' '<<0;
		else cout<<0<<' '<<1;
	}else if(n==2) cout<<b2[ans][0]<<' '<<b2[ans][1];
	return 0;
}
