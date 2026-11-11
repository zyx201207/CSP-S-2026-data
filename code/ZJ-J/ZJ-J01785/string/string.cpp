#include<bits/stdc++.h>
#define rd(x) cin>>x
#define pt(x) cout<<x
#define rep(i,x,y) for(ll (i)=(x);(i)<=(y);++i)
#define down(i,x,y) for(ll (i)=(x);(i)>=(y);--i)
#define rp(i,p) for(auto i:p)
#define mx(x,y) x=max(x,y)
#define mn(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;	
ll n,half,cnt,res;
ll posi,posj;
struct Seg{
	ll len;
	char ch;
}now,lst,p[N];
vector<Seg> vec;
void work(){
	rd(n);
	rep(i,1,n) rd(p[i].len),rd(p[i].ch),half+=p[i].len;
	half>>=1;
	rep(i,1,n){
		if(p[i].len+cnt<half) cnt+=p[i].len,vec.push_back(p[i]);
		else{
			vec.push_back({half-cnt,p[i].ch});
			break;
		}
	}
	cnt=posi=0,posj=n,now=vec[0],lst=p[n];
//	rp(i,vec) pt(i.len),pt(' '),pt(i.ch),pt('\n');
	while(true){
		if(posi>=vec.size()) break;
//		pt(now.len),pt(' '),pt(now.ch),pt('\n');
//		pt(lst.len),pt(' '),pt(lst.ch),pt('\n');
		if(now.ch!=lst.ch) res+=min(now.len,lst.len);
		if(now.len==lst.len) ++posi,--posj,now=vec[posi],lst=p[posj];
		else if(now.len<lst.len) ++posi,lst.len-=(now.len),now=vec[posi];
		else --posj,now.len-=(lst.len),lst=p[posj];
	}
	pt(res);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	T=1;
//	rd(T);
	while(T--) work();
	return 0;
}
/*
2
2 a
3 a
*/
/*
3
2 a
2 b
1 c
*/
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
