#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,d,q,c,usf;
vector<int>u;
const ll F=1e9;
struct st{//stop
	ll w;//kou->ting
	int trs;//number of transfer
	int t[507]={F};//tai->ting s[a].t[b]==station a  lineb tai to ting=time
}s[500007];
ll dis[3007][3007];
vector<int>l[507];//line
int v[5007];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].w;
	}
	for(int i=1;i<=n;i++){
		int k,a,tt;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>tt;
			l[i].push_back(a);
			s[a].t[i]=tt;
			s[i].trs++;
		}
	}//shuru
	//jiantu
	for(int i=1;i<=m;i++)
		if(s[i].trs>1){
			usf++;
			u.push_back(i);
		}
	for(int i=1;i<=n;i++){//line i,j<->k
		for(int j=0;j<l[i].size();j++){
			for(int k=0;k<l[i].size();k++){
				//if(s[l[i][k]].trs<=1)continue;//no transfer
				int kpt=s[l[i][k]].t[i]+s[l[i][j]].t[i];
				dis[l[i][k]][l[i][j]]=dis[l[i][j]][l[i][k]]=kpt;
				v[l[i][k]]++;
				v[l[i][j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){//zuiduanlu i->k 
		for(int j=0;j<v[i];j++){//midturn
			for(int k=0;k<v[i];k++){//to
				if(k==j)continue;
				dis[i][k]=dis[k][i]=min(dis[i][j]+dis[j][k],dis[i][k]);
			}
		}
	}
	while(q--){
		int fm,to;ll ans;
		cin>>fm>>to;
		cout<<s[fm].w+s[to].w+dis[fm][to]<<endl;
	}
	return 0;
}




