#include<bits/stdc++.h>
using namespace std;
struct at{
	int a,t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m);
	int an=0;
	for(int i=0;i<m;i++){
		cin>>w[i];
		an+=w[i];
	}
	int as=0;
	vector<vector<at> >att(n);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int za,zt;
			cin>>za>>zt;
			att[i].push_back({za,zt});
			as+=zt;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	cout<<as<<' '<<an;
	return 0;
} 


/*
bao zhe shi shi de xin tai da chu sai,shi neng xiang dao zhen jin fu sai le
lao shi mei jiao a,ta zhi jiao le J zu!
J he S dou shi di yi ci da
yi dao ye bu hui,kan bu dong
gan jue wo men zhe ge kao chang de do hen nb,jiu wo yi ge fw
yuan liang wo mei jiang guo zhe gao ji de dong xi
shang wu dou bu zhi dao neng da kai sheng xia de yang li
wo bu hui xie bao li!!!
zhe shu ru bi wo ming hai chang
xia ku li 
lao shi bu shi shuo S zu t1 he J zu t4 yi ge nan du ma?
wei shen me shang wu t4 zhi xie le 30min?
hao le,fang qi le
kai kai neng bu neng pian dian fen
ming nian zai zhan
zhu suo you ren AK
tian tian kai xin!
*/