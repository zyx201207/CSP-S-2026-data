#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=1e10;
long long c,n,m,d,q,w[5*N][30],k[505][30][2],st,en,ansn;
void tra(int c,int ans,int xi,int la,bool h){
	if(ans>=ansn)return;
	int o=1;
	while(k[xi][o][0]!=la){
	o++;
	//if(o>k[xi][0][0])return;
	}
	if(h)ans+=k[xi][o][1];
	o++;
	ans+=k[xi][o][1];
	//if(vis[xi][o]!=c){
	//vis[xi][o]=c;
		if(k[xi][o][0]==en){
		ansn=min(ansn,ans);
		//cout<<ansn<<" ";
	}else{
		for(int i=1;i<=w[k[xi][o][0]][25];i++){
			if(w[k[xi][o][0]][i]==xi){
			//cout<<k[xi][o][0]<<" "<<w[k[xi][o][0]][i]<<" ";
			tra(c,ans-k[xi][o][1],w[k[xi][o][0]][i],k[xi][o][0],0);
			}else {
			//cout<<k[xi][o][0]<<" "<<w[k[xi][o][0]][i]<<" ";
			tra(c,ans,w[k[xi][o][0]][i],k[xi][o][0],1);
			}
		}
		}
	//}else return;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i][0];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i][0][0];
		for(int j=1;j<=k[i][0][0];j++){
			cin>>k[i][j][0]>>k[i][j][1];
			w[k[i][j][0]][25]++;
			//cout<<w[k[i][j][0]][25]<<" ";
			w[k[i][j][0]][w[k[i][j][0]][25]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>en;
		ansn=M;
		for(int j=1;j<=w[st][25];j++){
			tra(i,w[st][0]+w[en][0],w[st][j],st,1);
		}	
		cout<<ansn<<"\n";
	}
	return 0;
} 
