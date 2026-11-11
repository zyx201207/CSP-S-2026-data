#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],len=0,now[N],ans[N];
bool used[N];
inline void init(){
	for(ll i=0;i<=m;i++) used[i]=false;
	for(ll i=0;i<=m;i++) now[i]=0;
	len=0;
	return ;
} 
inline void count(){
	for(ll i=1;i<=len;i++) ans[now[i]]++;
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		init();
		for(ll j=i;j<=n;j++){
			if(used[a[j]]==true){
				ll idx=0;
				for(ll k=1;k<=len;k++){
					if(now[k]==a[j]){
						idx=k;
						break;
					}
				}
				ll down=idx-1;
				for(ll k=idx;k<=len;k++){
					used[now[k]]=false;
					now[k]=0;
				}
				len=down;
				if(len<0) len=0;
			}
			now[++len]=a[j];
			used[a[j]]=true;
		}
		count();
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0; 
}
