#include<bits/stdc++.h>
#define int long long
const int N=2e5+1e2;
using namespace std;
int n,nl,ans,l;
struct node{
int st,ed,ps;
};
node a[N];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		int len;
		cin>>len>>ch;
		a[i].st=a[i-1].ed+1;
		a[i].ed=a[i].st+len-1;
		a[i].ps=ch-'a';
		l+=len;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	int pos=n,sq=l;
	for(int i=1;i<=n;i++){
//		st to ed is ps
		if(pos<=i) break;
//		l+1-st to l+1-ed is must be a[i].ps
		while(a[pos].st>l+1-a[i].ed){
			if(a[pos].ps!=a[i].ps) ans+=(sq-a[pos].st+1);
			sq=a[pos].st-1;
			pos--;
			if(pos==i){
				cout<<ans;
				return 0;
			}
		}
		if(a[pos].ps!=a[i].ps) ans+=a[i].ed-(l+1-sq)+1;
		sq-=(a[i].ed-(l+1-sq)+1);
	}
	cout<<ans;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/