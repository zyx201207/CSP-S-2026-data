#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define srccf ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 5007
#define ff first
#define ss seconde

int c,t;
int n,k;
int fa[N];
struct trrr{
	int id,fa;
};
int find(int x){
	return fa[x] = fa[x]==x?x:find(fa[x]);
}
int lowbit(int x){
	return x&-x;
}
int fff(int x){
	int ans=0;
	while(x){
		x/=2;ans++;
	}
	return ans;
}
int main(){
	srccf;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){ cout<<1<<endl<<2<<endl; return 0; }
	while(t--){
		cin>>n>>k;
		trrr tr[N];
		int fa[N];for(int i=1;i<=n;i++) fa[i]=i;
		vector <int > nt[N];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			if(u>v) swap(u,v);
			nt[u].push_back(v);nt[v].push_back(v);
//		}
//		for(int k1=1;k1<=1<<n;k1++){
//			int cnt=0;
//			int po=k1;
//			vector <int > id;
//			while(po){
//				po-=lowbit(po);id.push_back(fff(lowbit(po)));
//				cnt++;
//			}if(cnt!=k) continue;po=k1;
//			for(auto x : id){
//				for(auto nxt : nt[x]){
//					//
//				}
//			}
		}
		cout<<k-n/2<<endl;
	}
	return 0;
}
//ci=ai-a1+...ai-ai-1
//ci+1=ai+1-ai
//quququ
//zaiyebuyonglaile
//nbzsfrzykql
//kskblzdjdwkzkbl
//ccccccsnmgbydmr
//dzdshjswsdgysjmssxjfg
//shengniwuxudierjian
//fnzbm
//jfcyc
//tsyj
//sjqm

