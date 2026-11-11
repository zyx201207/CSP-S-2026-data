//
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int c,t,n,d,x[2000005],a[2000005],k;
int to[2000005];
struct{
	void solve(){
		if(n==1)
			cout<<"0\n";
		else if(d<2*(x[2]-x[1]))
			cout<<"0\n";
		else if(d>=x[2]-x[1])
			cout<<max(0ll,n-(2*(d/(x[2]-x[1]))-1))<<endl;
		else
			cout<<"0\n";
	}
}solve1;
int r1,r2,r3;
int get(int x){
	if(x<=r3)
		return 3;
	if(x<=r2)
		return 2;
	if(x<=r1)
		return 1;
	return 0;
}
int calc(int l,int r){
	int k=((x[r]-x[l]-1)/d+1)<<1,res=0;
	rep(i,l,r){
		to[0]=i;
		to[1]=a[i];
		r1=a[i];
		r2=r3=i;
		rep(now,2,k){
			to[now]=a[to[now-1]];
			int pos1=0,pos2=0,pos3=0;
			per(j,to[now-1],1){
				rep(tmp,1,get(j)){
					if(!pos1)
						pos1=a[j];
					else if(!pos2)
						pos2=a[j];
					else if(!pos3)
						pos3=a[j];
				}
				if(pos3)
					break;
			}
			r1=pos1;
			r2=pos2;
			r3=pos3;
			res+=r2-r3;
		}
	}
	return res;
}
void solve(){
	cin>>n>>d;
	rep(i,1,n)
		cin>>x[i];
	if(c>=11&&c<=12){
		solve1.solve();
		return;
	}
	rep(i,1,n)
		a[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
	int lst=1,ans=0;
	rep(i,1,n)
		if(x[i]-x[i-1]>d){
			ans+=calc(lst,i-1);
			lst=i;
		}
	ans+=calc(lst,n);
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
/*
红温了
应该是72吧
记录i到j最短的距离以及最短路条数
额啊，migrate5前两个test怎么不对
乐，不管同步流的来了
17:55 72 
*/

