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
const int N=1e5+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
int c,n,d,cnt,res,minn,pos;
int num[N];
void dfs(int x,int y,int now,int step){
	if(now==y){
		++cnt;
		return ;
	}
	if(step>=minn) return ;
	rep(i,now+1,y) if(num[i]-num[now]<=d) dfs(x,y,i,step+1); 
}
void work(){
	rd(n),rd(d),res=0;
	rep(i,1,n) rd(num[i]);
	rep(i,1,n)
		rep(j,i+1,n){
			pos=i,minn=0;
			while(pos<=j){
				if(num[j]-num[pos]<=d){
					++minn;
					break;
				}
				rep(k,pos+1,j){
					if(num[k]-num[pos]>d){
						pos=k-1,++minn;
						break;
					}
				} 
			}
			cnt=0,dfs(i,j,i,0);
			if(cnt==2) ++res;
//			pt(i),pt(' '),pt(j),pt('\n');
		}
	pt(res),pt('\n');
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
//	T=1;
	rd(c),rd(T);
	while(T--) work();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*

*/
