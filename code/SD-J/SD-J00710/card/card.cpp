#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
ll n,m,a[N],b[N],nxt[N],pre[N];
bool vis[N],live[N];
ll can_cnt[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
	    cin>>a[i];
	    if(!vis[a[i]]){
		    vis[a[i]]=1;
		    nxt[a[i]]=i;   
	    }else{
	    	pre[i]=nxt[a[i]];
	    	nxt[a[i]]=i;
		}
	}
	for(ll i=1;i<=n;i++){
		ll len=n-i+1;
		for(ll j=1;j<=len;j++){
			b[j]=a[i+j-1];
		    can_cnt[b[j]]++;
		    live[j]=1;
		}
		for(ll j=1;j<=n;j++){
	        if(!vis[b[j]]){
		        vis[b[j]]=1;
		        nxt[b[j]]=j;   
	        }else{
	    	    pre[j]=nxt[b[j]];
	        	nxt[b[j]]=j;
		    }
	    }
		for(ll j=1;j<=len;j++){
			if(pre[j]!=0){
				if(live[pre[j]]){
			        for(ll k=pre[j];k<j;k++){
				        if(live[k]) can_cnt[k]--;
				        live[k]=0;
				    }
				}
			}
		}
		for(ll j=1;j<=len;j++){
			if(can_cnt[b[j]]>0) ans[b[j]]++;
			can_cnt[b[j]]=0;
		}
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" "; 
	return 0;
} 
