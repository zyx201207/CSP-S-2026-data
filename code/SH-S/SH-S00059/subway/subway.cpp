#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int a,b;
int w[801000];
int dis[810][810];
struct node{
	int fr;
	int t;
};
int mn;
vector<node> mp[800010];
int rd(){
	t=0;
	char c;
	while(1){
		c=getchar();
		if(c==' '||c=='\n'){
			return t;
		}
		t=t*10+c-'0';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cd,n,m,d,q,k,ts,ty;
	cd=rd();
	n=rd();
	m=rd();
	d=rd();
	q=rd();
	for(int i=1;i<=m;i++){
		w[i]=rd();
	}
	for(int i=1;i<=n;i++){
		k=rd();
		for(int j=1;j<=k;j++){
			ts=rd();
			ty=rd();
			mp[ts].push_back({ty,i});
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=990000000000000;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<mp[i].size()-1;j++){
			for(int to=j+1;to<mp[i].size();to++){
				//cout<<i<<' '<<j<<' '<<to<<endl;
				if(dis[mp[i][j].t][mp[i][to].t]>mp[i][j].fr+mp[i][to].fr){
					dis[mp[i][j].t][mp[i][to].t]=mp[i][j].fr+mp[i][to].fr;
					dis[mp[i][to].t][mp[i][j].t]=mp[i][j].fr+mp[i][to].fr;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
				dis[k][j]=dis[j][k];
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		cout<<dis[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		mn=99999999999999;
		for(int j=0;j<mp[a].size();j++){
			for(int to=0;to<mp[b].size();to++){
				mn=min(mn,mp[a][j].fr+mp[b][to].fr+dis[mp[a][j].t][mp[b][to].t]);
			}
		}
		cout<<mn+w[a]+w[b]<<endl;
	}
	return 0;
}
