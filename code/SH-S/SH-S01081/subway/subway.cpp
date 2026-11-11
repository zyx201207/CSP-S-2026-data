#include<bits/stdc++.h>
#define mps make_pair
using namespace std;
typedef pair<int,pair<int,int > > state;
//dis,(station,subway i)
typedef long long ll; 
const int N=500,M=(int)5e5,D=20;
int c,n,m,d,q;
ll w[M+10];//鍏ュ彛->绔欏巺
ll sq[M+10][D+2];//绔欏巺->绗琁涓嚎璺殑绔欏彴
ll sw[M+10][N+10];//绗嚑鏉＄嚎璺�(鍏ㄥ眬)鏄竴涓珯鐐圭殑绗嚑鏉＄嚎璺� 
ll sid[N+10][D+2];//绾胯矾缂栧彿(绔欑偣)鏄鍑犳潯绾胯矾(鍏ㄥ眬)
vector<int> stations[M+10];//涓€涓嚎璺粡杩囩殑绔欑偣 
int cnt[500000+50];


//0->绔欏巺 
//1锝�20->绔欏彴 
ll dijk(int stt,int dest){
	//memset(dis,0x7f,sizeof dis);
	ll dis[N+10][D+2];
	dis[stt][0]=0;
	set<state> ss;
	ss.insert(mps(0,mps(stt,0)));
	while(not ss.empty()){
		state bg=*ss.begin();
		ll ndis=bg.first;
		ll u =bg.second.first;//node
		ll uw =bg.second.second;//id
		//printf("station#%lld:Platform#%lld    =  %lld\n",u,uw,ndis);
		ss.erase(ss.begin());
		if(uw==0){
			//杞Щ鍒扮珯鍙�
			for(int i=1;i<=cnt[u];i++){
				//cout<<"OK"<<sq[u][i]<<"\n";
				if(ndis+sq[u][i]<dis[u][i]){
					//cout<<"better\n";
					dis[u][i]=ndis+sq[u][i];
					ss.insert(mps(dis[u][i],mps(u,i)));
				}
			}
		}else{
			//杞Щ鍒板叾浠栫珯鐐�/绔欏巺
			//鑾峰彇杩欎釜绾胯矾鐨勬墍鏈夌珯鐐�
			int currentTrain=sid[u][uw];
			for(int i=0;i<stations[currentTrain].size();i++){
				int destS=stations[currentTrain][i];
				
				int destPlat=sw[currentTrain][destS];
				if(ndis<dis[destS][destPlat]){
					dis[destS][destPlat]=ndis;
					ss.insert(mps(dis[destS][destPlat],
							  mps(destS,destPlat)));
				}
			}
			//鍘荤珯鍘�
			if(ndis+sq[u][uw]<dis[u][0]){
				dis[u][0]=ndis+sq[u][uw];
				ss.insert(mps(ndis+sq[u][uw],mps(u,0)));
			}
		}
	}
	return dis[dest][0];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		//cin>>w[i];
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int ak,tk;
			scanf("%d%d",&ak,&tk);//station,dist
			stations[i].push_back(ak);
			cnt[ak]++;
			//cerr<<"PHASE1";
			if(cnt[ak]>20 or ak>500){
				cerr<<"ERROR"<<cnt[ak]<<" "<<ak<<" "<<tk<<"\n";
			}
			sq[ak][cnt[ak]]=tk;
			//cerr<<"PHASE2";
			sw[i][ak]=cnt[ak];
			//cout<<"PHASE3";
			sid[ak][cnt[ak]]=i;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dijk(x,y)+w[x]+w[y]);
	}
	
}
