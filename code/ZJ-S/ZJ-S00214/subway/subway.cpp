#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,it,vis[1010][1010],st,fi;
long long dis[1010][1010],ans;
struct sta{
	int ol,now;
	long long t;
}a[1010][1010];
struct node{
	int v;
	long long zhi;
};
struct stio{
	int to;
	long long t;
};
struct li{
	long long t;
	int nam;
}stsa[25],fisa[25];
long long stat[1010];
vector<node> mp[1010];
vector<stio> stion[1010];
int cou_st,cou_fi;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>stat[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		int la;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].ol>>a[i][j].t;
			int to=a[i][j].ol;
			it++;
			a[i][j].now=it;
			int nto=a[i][j].now;
			stion[to].push_back({nto,a[i][j].t});
			if(j!=1){
				mp[la].push_back({nto,0});
				mp[nto].push_back({la,0});
			}
			if(stion[to].size()>1){
				for(int k=0;k<stion[to].size();k++){
					stio num=stion[to][k];
					if(num.to==nto) continue;
					mp[num.to].push_back({nto,num.t+a[i][j].t});
				}
			}
			la=nto;
		}
	}
	for(int i=1;i<=it;i++){
		for(int j=1;j<=it;j++) dis[i][j]=1e17;
	}
	for(int s=1;s<=it;s++){
		dis[s][s]=0;
		for(int i=1;i<=it;i++){
			int ct=0;
			long long mn=1e17;
			for(int j=1;j<=it;j++){
				if(dis[s][j]<mn && !vis[s][j]){
					mn=dis[s][j];
					ct=j;
				}
			}
			vis[s][ct]=1;
			for(int j=0;j<mp[ct].size();j++){
				int tom=mp[ct][j].v;
				long long sum=mp[ct][j].zhi+dis[s][ct];
				dis[s][tom]=min(dis[s][tom],sum);
				dis[tom][s]=dis[s][tom];
			}
		}
	}
	while(q--){
		cin>>st>>fi;
		ans=stat[st]+stat[fi];
		long long numx=1e17;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j].ol!=0 && a[i][j].ol==st){
					cou_st++;
					stsa[cou_st].nam=a[i][j].now;
					stsa[cou_st].t=a[i][j].t;
				}
				if(a[i][j].ol!=0 && a[i][j].ol==fi){
					cou_fi++;
					fisa[cou_fi].nam=a[i][j].now;
					fisa[cou_fi].t=a[i][j].t;
				}
			}
		}
		for(int i=1;i<=cou_st;i++){
			for(int j=1;j<=cou_fi;j++){
				li star=stsa[i],fish=fisa[j];
				numx=min(numx,star.t+fish.t+dis[star.nam][fish.nam]);
			}
		}
		cout<<ans+numx<<endl;
	}
	return 0;
}
