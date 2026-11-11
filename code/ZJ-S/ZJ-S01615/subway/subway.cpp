#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct nd{int id,t,yuan;};
int qwq,n,m,d,_,w[250005],minn[250005];
vector<vector<int> > sbw;//地铁的这个线路的这个站点 
vector<vector<int> > sbt;//对应的时间 
vector<vector<int> > stt;//每个站点连接了哪几个地铁 
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> qwq >> n >> m >> d >> _;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=0;i<=m;i++){
		vector<int> usls;
		stt.push_back(usls);
	}
	for(int i=1;i<=n;i++){
		int x;
		vector<int> num;
		vector<int> t;
		cin >> x;
		for(int j=1;j<=x;j++){
			int usls1,usls2;
			cin >> usls1 >> usls2;
			num.push_back(usls1);
			t.push_back(usls2);
			
			stt[usls1-1].push_back(i-1);
		}
		sbw.push_back(num);
		sbt.push_back(t);
	}
	while(_--){
		int x,y,ans=INT_MAX;
		cin >> x >> y;
		for(int i=1;i<=m;i++) minn[i]=INT_MAX;
		queue<nd> q;
		nd usls;
		usls.id=x,usls.t=0;
		q.push(usls);
		minn[x]=0;
		while(!q.empty()){
			nd f=q.front();
			q.pop();
			if(f.id==y) ans=min(ans,f.t);
			for(int i=0;i<stt[f.id-1].size();i++){
				int subwa=stt[f.id-1][i];
				int usls2;//当前站点在这个线路中的编号 
				for(int j=0;j<sbw[subwa].size();j++){
					if(sbw[subwa][j]==f.id-1){
						usls2=j;
						break;
					}
				}
				for(int j=0;j<sbw[subwa].size();j++){
					if(sbw[subwa][j]==f.id-1) continue;
					int k=sbt[subwa][usls2]+sbt[subwa][j] + f.t;
					if(k<minn[sbw[subwa][j]]){
						minn[sbw[subwa][j]]=k;
						nd usls1;
						usls1.id=sbw[subwa][j],usls1.t=k,usls1.yuan=f.id;
						q.push(usls1);
					}
				}
			}
		}
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
}
