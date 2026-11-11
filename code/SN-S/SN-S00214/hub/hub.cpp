#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;
int n,k;
int popcnt(int mmm){
	int ans=0;
	while(mmm){
		ans++;
		mmm-=(mmm&(-mmm));
	}
	return ans;
}
int DIST=1e9;
void hubdist(int p,int msk,int fa,int dph){
	if(msk&(1<<(p-1)))DIST=min(DIST,dph);//我在研究所的距离
	for(auto i:G[p]){
		if(i==fa)continue;
		hubdist(i,msk,p,dph+1);
	} 
}
bitset<500005>bst;
void vis(int mask,int p,int fa){
	bst[p]=1;
	for(auto i:G[p]){
		if(fa==i)continue;
		if((1<<(i-1))&mask)vis(mask,i,p);
	}
}
bool checkltk(int mask){//是否<=2个 
    bst.reset();//bitset代替bool[] 
    int cnt=0;
	for(int point=1;point<=n;point++){
		if(mask&(1<<(point-1))){
			if(!bst[point]){
				cnt++;
				if(cnt>2)return 0;
				vis(mask,point,0);
			}
		}
	}
	return cnt<=2;
}
void sol(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	G.clear();
	cin>>n>>k;
	G.resize(n+5);
	int ans=1e9;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
    for(int mask=0;mask<(1<<n);mask++){
    	if(popcnt(mask)!=k)continue;
    	if(!checkltk(mask))continue;
    	int BJ=0;
    	for(int i=1;i<=n;i++){
    		if(mask&(1<<(i-1)))continue;//d(i)=0
    		DIST=1e9;
			hubdist(i,mask,0,0); 
			BJ=max(BJ,DIST);
		}
		ans=min(ans,BJ);
	}
	cout<<ans<<'\n';
}
int main(){
	int t,c;cin>>c>>t;
	while(t--)sol();
	return 0;
}
