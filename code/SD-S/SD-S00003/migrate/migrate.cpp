#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const ll N=2e6+10;
void KApfme(){
	/*
	考虑n^2/n^3做法，枚举两个端点，然后check一下是否恰好有两条
	这里提供一个O(玄学)做法 
	*/
}
ll n,d;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	FAST
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ll sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ll st=i,ed=j;
				ll ost=0;
				ll s=0;//上一次跳到的点的编号
				ll q=0;
				ll flag=0;
				while(st<ed){
					ll w=x[st]+d;
					ll nw=upper_bound(x+1,x+n+1,w)-x;
					nw--;
					nw=min(ed,nw);
					if(s!=0){
						for(int k=st-1;k>s;k--){
							if(x[nw]-x[k]<=d){
								q++;
							}else{
								break;
							}
						}
						for(int k=st+1;k<nw;k++){
							if(x[k]-x[s]<=d){
								q++;
							}else{
								break;
							}
						}
						s=st;
						st=nw;
					}else{
						s=st;
						st=nw;
					}
					if(ost==st){
						flag=1;
						break;
					}
					ost=st;
				}
				if(flag==0&&q==1){
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	} 
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
