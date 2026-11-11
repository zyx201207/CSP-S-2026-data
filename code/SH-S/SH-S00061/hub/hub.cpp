#include<bits/stdc++.h>
using namespace std;

int cid,T,n,K,fath[1000005];
vector<int>mp[1000005];
int bf[4005],bf2[4005],mdep[1000005],bg1[4005][4005],bg2[4005][4005];
int stk[4005],pt1;bool vis[4005];

void dfs(int x,int fa){
	fath[x]=fa;
	for(auto y:mp[x])if(y!=fa)dfs(y,x);
}

void brdfs1(int x,int fa){
	for(auto y:mp[x])if(y!=fa){
		brdfs1(y,x);bf[x]=max(bf[x],bf[y]+1);
	}
}

void brdfs2(int x,int fa){
	stk[++pt1]=x;vis[x]=1;
	int mxm=bf2[x];
	for(auto y:mp[x])if(y!=fa){
		bf2[y]=max(bf2[y],mxm+1);mxm=max(mxm,bf[y]+1);
	}
	reverse(mp[x].begin(),mp[x].end());
	mxm=0;
	for(auto y:mp[x])if(y!=fa){
		bf2[y]=max(bf2[y],mxm+1);mxm=max(mxm,bf[y]+1);
	}
	for(auto y:mp[x])if(y!=fa)brdfs2(y,x);
}

void brdfs3(int x,int fa,int rot){
	for(auto y:mp[x])if(y!=fa&&vis[y]){
		brdfs3(y,x,rot);mdep[x]=max(mdep[x],mdep[y]+1);
	}
	if(rot>0)bg1[rot][mdep[x]]++;else bg2[-rot][mdep[x]]++;
}

int mdep2[1000005],dia[1000005],dia2[1000005];

void ddfs(int x,int fa){
	for(auto y:mp[x])if(y!=fa){
		ddfs(y,x);dia[x]=max(dia[x],max(dia[y],mdep[x]+mdep[y]+1));
		mdep[x]=max(mdep[x],mdep[y]+1);
	}
}

void dfsEX(int x,int fa){
	int mxm=(x==1?0:mdep2[x]+1),mxd=dia2[x];
	for(auto y:mp[x])if(y!=fa){
		dia2[y]=max(dia2[y],max(mxd,mxm+mdep2[y]));
		mdep2[y]=max(mdep2[y],mxm);
		mxd=max(mxd,max(dia[y],mxm+mdep[y]+1));mxm=max(mxm,mdep[y]+1);
	}
	reverse(mp[x].begin(),mp[x].end());
	mxm=mxd=0;
	for(auto y:mp[x])if(y!=fa){
		dia2[y]=max(dia2[y],max(mxd,mxm+mdep2[y]));
		mdep2[y]=max(mdep2[y],mxm);
		mxd=max(mxd,max(dia[y],mxm+mdep[y]+1));mxm=max(mxm,mdep[y]+1);
	}
	for(auto y:mp[x])if(y!=fa)dfsEX(y,x);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>cid>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			mp[x].push_back(y);mp[y].push_back(x);
		}
		dfs(1,1);
		if(cid<=10){
			brdfs1(1,1);brdfs2(1,1);
			for(int i=1;i<=n;i++)bf[i]=max(bf[i],bf2[i]);
			{
				int mnm=0;for(int i=1;i<=pt1;i++)if(!mnm||bf[stk[i]]<bf[mnm])mnm=stk[i];
				brdfs3(mnm,mnm,1);
				while(pt1){vis[stk[pt1]]=0;pt1--;}
			}
			for(int i=1;i<=n;i++)bf[i]=bf2[i]=mdep[i]=0;
			for(int x=2;x<=n;x++){
				int y=fath[x];
				brdfs1(x,y);brdfs2(x,y);
				for(int i=1;i<=n;i++)bf[i]=max(bf[i],bf2[i]);
				{
					int mnm=0;for(int i=1;i<=pt1;i++)if(!mnm||bf[stk[i]]<bf[mnm])mnm=stk[i];
					brdfs3(mnm,mnm,x);
					while(pt1){vis[stk[pt1]]=0;pt1--;}
				}
				brdfs1(y,x);brdfs2(y,x);
				for(int i=1;i<=n;i++)bf[i]=max(bf[i],bf2[i]);
				{
					int mnm=0;for(int i=1;i<=pt1;i++)if(!mnm||bf[stk[i]]<bf[mnm])mnm=stk[i];
					brdfs3(mnm,mnm,-x);
					while(pt1){vis[stk[pt1]]=0;pt1--;}
				}
				for(int i=1;i<=n;i++)bf[i]=bf2[i]=mdep[i]=0;
			}
			for(int i=1;i<=n;i++)for(int j=n;j>=1;j--){bg1[i][j-1]+=bg1[i][j];bg2[i][j-1]+=bg2[i][j];}
			for(int i=0;i<=n;i++){
				bool satis=(max(bg1[1][i],1)<=K);
				for(int j=2;j<=n;j++)satis|=(max(bg1[j][i],1)+max(bg2[j][i],1)<=K);
				if(satis){cout<<i<<'\n';break;}
			}
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)bg1[i][j]=bg2[i][j]=0;
			for(int i=1;i<=n;i++)mp[i].clear();
			continue;
		}
		if(cid==11||cid==12){
			ddfs(1,1);dfsEX(1,1);
			int ans=(dia[1]+1)/2;
			for(int i=2;i<=n;i++)ans=min(ans,max((dia[i]+1)/2,(dia2[i]+1)/2));
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++)mdep[i]=mdep2[i]=dia[i]=dia2[i]=0;
			for(int i=1;i<=n;i++)mp[i].clear();
		}
		if(cid==13||cid==14){
			int L=-1,R=n-1,m=(n-1>>1);
			while(R-L>1){
				int md=(L+R>>1);
				if(md*2>=m+1){R=md;continue;}
				if(md==0&&K<n){L=md;continue;}
				if(K==n){R=md;continue;}
				bool satis=0;
				for(int i=1;i<m;i++){
					if(max(i+1-md*2,1)+max(m-i+1-md*2,1)<=K)satis=1;
				}
				if(satis)R=md;else L=md;
			}
			cout<<R<<'\n';
			for(int i=1;i<=n;i++)mp[i].clear();
		}
	}
	return 0;
}
