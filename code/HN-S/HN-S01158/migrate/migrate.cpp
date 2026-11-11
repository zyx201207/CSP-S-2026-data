#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll a[N];int n;
int nxt[N];
inline int gtlw(ll x){
	return lower_bound(a+1,a+1+n,x)-a;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		ll l;cin>>n>>l;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			nxt[i]=gtlw(a[i]-l);
			if(nxt[i]==i)nxt[i]=-1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=l)continue;
				int x=j,num=0,num1=0;
				while(x>i){
					x=nxt[x],num++;
					if(x==-1)break;
				}
				x=nxt[j]+1;
				if(x==j)continue;
				while(x>i){
					x=nxt[x],num1++;
					if(x==-1)break;
				}
				if(num1!=num)continue;
				x=nxt[j]+2,num=0;
				if(x==j){ans++;continue;}
				while(x>i){
					x=nxt[x],num++;
					if(x==-1)break;
				}
				if(num!=num1)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
