#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct r{
	int siz;
	char x;
}c[114514<<1];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].siz>>c[i].x;
//		num+=c[i].siz;
	}
	int l=1,r=n;
	while(l<r){
//		cout<<l<<" "<<r<<" "<<ans<<endl;
		if(c[l].x==c[r].x){
			int t=min(c[l].siz,c[r].siz);
			c[l].siz-=t;
			c[r].siz-=t;
			if(!c[l].siz) l++;
			if(!c[r].siz) r--;
		}
		else{
			int t=min(c[l].siz,c[r].siz);
			ans+=t;
			c[l].siz-=t;
			c[r].siz-=t;
			if(!c[l].siz) l++;
			if(!c[r].siz) r--;
		}
	}
	cout<<ans;
	return 0;
}
