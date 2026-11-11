#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,length[505][505],n,m,T,d,q,w[500005],k[505],t,heada[500005],cnta,cntr,headr[505];
struct rec{
	ll belongrail,timee,nextt;
	//belongrail:该站台的其中一个rail
	//timee:从该站台的站厅到该rail的时间
}a[500005];
struct recc{
	ll wei,timee,nextt;
	//wei:与该rail1相连的rail2
	//timee:出该rail1走到rail2的时间
}rails[100005];
priority_queue<pair<int,int> >dotts;
void add1(int x,int y,int z){
	a[++cnta].belongrail=y;
	a[cnta].nextt=heada[x];
	a[cnta].timee=z;
	heada[x]=cnta;
}
void add2(int x,int y,int z){
	rails[++cntr].wei=y;
	rails[cntr].timee=z;
	rails[cntr].nextt=headr[x];
	headr[x]=cntr;
}
ll readd(){
	char c=getchar();
	ll t=0;
	while(c>='0'&&c<='9'){
		t=t*10+c-'0';
		c=getchar();
	}
	return t;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	getchar();
	for(int i=1;i<=m;++i)w[i]=readd();
	for(int i=1;i<=n;++i){
		k[i]=readd();
		for(int j=1;j<=k[i];++j){
			int zhan=0;
			zhan=readd();t=readd();
			for(int k=heada[zhan];k;k=a[k].nextt){
				add2(i,a[k].belongrail,a[k].timee+t);
				add2(a[k].belongrail,i,a[k].timee+t);
			}
			add1(zhan,i,t);
		}
	}
	
	memset(length,0x1f,sizeof(length));
	
	for(int i=1;i<=n;++i){
		length[i][i]=0;
		while(!dotts.empty())dotts.pop();
		dotts.push(make_pair(-0,i));
		while(!dotts.empty()){
			int u=dotts.top().second;
			dotts.pop();
			for(int j=headr[u];j;j=rails[j].nextt){
				int v=rails[j].wei,s=rails[j].timee;
				if(length[i][v]>length[i][u]+s){
					length[i][v]=length[i][u]+s;
					dotts.push(make_pair(-length[i][v],v));
				}
			}
		}
	}
	
	for(int i=1;i<=q;++i){
		int x=0,y=0;
		cin>>x>>y;
		ll ans=1e18;
		for(int j=heada[x];j;j=a[j].nextt){
			int xbelong=a[j].belongrail;
			for(int k=heada[y];k;k=a[k].nextt){
				int ybelong=a[k].belongrail;
				ans=min(ans,length[xbelong][ybelong]+a[j].timee+a[k].timee);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}