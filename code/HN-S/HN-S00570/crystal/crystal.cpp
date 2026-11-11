#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;ll f=1;char c=getchar();
	while(c<'0'||'9'<c){if(c='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
const ll N=500005;
ll a[N];
ll v[N];
ll n,m,ans=-1;
void dfs(ll k){
	if(k>=n+1){
		ll maxx=-1e16;
		ll mcnt=0;
		for(ll i=1;i<=n;i++){
			if(v[i]==1){
				if(maxx<a[i]){
					mcnt=i;
					maxx=a[i];
				}
			}
		}
		ll num=0,cnt=0;
		for(ll i=n;i>=1;i--){
			if(v[i]==1){
				num+=a[mcnt]-a[i];
				cnt++;
				if(num>m)break;
			}
		}
		if(num<=m){
			ans=max(ans,cnt);
		}
		return;
	}
	v[k]=1;
	dfs(k+1);
	v[k]=0;
	dfs(k+1);
}
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		dfs(1);
		cout<<ans;
	}
	else{
		ans=0;
		for(ll l=1,r=2;l<=r&&r<=n;){
			ll ls_r= a[r]-a[l];ll ls_l= a[r]-a[r-1];
			ll ls_sum=(ls_l+ls_r)*((ls_r-ls_l)/((a[2]-a[1]))+1)/2;
			//printf("(%lld+%lld)*((%lld-%lld)/((%lld-%lld))+1)/2 ",ls_l,ls_r,ls_r,ls_l,a[2],a[1]);
			//cout<<l<<" "<<r<<" "<<ls_l<<" "<<ls_r<<" "<<ls_sum<<" "<<ans<<endl;
			if (ls_sum<=m){
				ans=max(ans,r-l+1);
				//cout<<r-l+1<<endl;
				r++;
			}
			else if(ls_sum>m){
				l++;
			}
		}
		cout<<ans; 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 8
-3 -1 2 2 7

4

5 5
1 2 4 8 9

3


5 10
1 2 3 4 5

5

*/
