#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ull=unsigned long long;
using i128=__int128;
using Pii=pair<int,int>;
const int maxN=1e5+10;
struct node{
	LL val;
	char ch;
};
LL n,len;
char s;
vector<node> v;
LL work(){
	LL ans=0;
	int l=0,r=len-1;
	while(l<=r){
		if(v[l].val>v[r].val){
			if(v[l].ch!=v[r].ch) ans+=v[r].val;
//cout<<1<<' '<<"ans="<<ans<<'\n';
			v[l].val-=v[r].val;
			r--;
		}else if(v[l].val<v[r].val){
			if(v[l].ch!=v[r].ch) ans+=v[l].val;
//cout<<2<<' '<<"ans="<<ans<<'\n';
			v[r].val-=v[l].val;
			l++;
		}else{
			if(v[l].ch!=v[r].ch) ans+=v[l].val;
//cout<<3<<' '<<"ans="<<ans<<'\n';
			l++;r--;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		LL x;
		char c;
		cin>>x>>c;
		v.push_back({x,c});
	}
	len=v.size();
	work();
	return 0;
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
