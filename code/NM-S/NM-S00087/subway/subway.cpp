#include<bits/stdc++.h>

using namespace std;
const int MM=5*1e5+10;
int c,n,m,d,q;
int x,y;
bool fa=0;
bool fb=0;
queue<int> k;
struct node{
	int val;
	int num;
};
struct station{
	int idx;
	int w;
	vector<int> ttot;
	vector<int> utov;
	int ttotl=0;
	int utovl=0;
};

station dot[MM];
bool vis[MM]={0};
void bfs(int x,int y) {
	queue<node> q;
	q.push({0,x});
	node now;
	long long ans=dot[x].w +dot[y].w ;
	while(!q.empty()){
		now=q.front();
		q.pop();
		//cout<<"当前站和数值是： "<<now.num <<' ' << now.val << endl;
		//cout<<"当前站是否遇到过: "<<vis[now.num ]<<endl;
		if(vis[now.num ]) {
			continue;
		}
		vis[now.num]=1;
		if(now.num==y) {
			cout<<now.val+ans<<endl;
			return ;
		}
		
		int len1=dot[now.num ].ttotl; 
		//cout<<"这个站所经过的路线数"<<dot[now.num ].ttotl<<endl; 
		int len2=dot[now.num ].utovl;
		//cout<<"这个站能到的站的数量"<<dot[now.num ].utovl<<endl; 
		for(int i=0;i<len1;++i){
			for(int j=0;j<len2;++j){
				//cout<<"当前要去的站："<<dot[now.num].utov[j]<<endl; 
				//cout<<"当前站是否遇到过: "<<vis[dot[now.num].utov[j]]<<endl;
				if(vis[dot[now.num].utov[j]]) {
					continue;
				}
				//cout<<"需要的花费： "<<dot[now.num].ttot[i]+dot[dot[now.num].utov[j]].ttot[i]+now.val <<endl; 
				q.push({dot[now.num].ttot[i]+dot[dot[now.num].utov[j]].ttot[i]+now.val ,dot[now.num].utov[j]});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c>=7&&c<=11){
		fa=1;
	}
	if(c>=12&&c<=19){
		fb=1;
	}
	for(int i=1;i<=m;++i){
		dot[i].idx =i;
		cin >> dot[i].w ;	
	}
	int a,t,ki;
	for(int i=1;i<=n;++i){
		cin >> ki;
		for(int j=1;j<=ki;++j){
			cin >> a >> t;
			k.push(a);
			dot[a].ttot.push_back(t);
			dot[a].ttotl++;
			//cout<<"从"<<a<<"的站厅到"<<a<<"的第"<<i<<"条路线的站台需要"<<dot[a].ttot[dot[a].ttotl-1]<<"的时间"<<endl;
		}
		for(int some=0;some<ki;++some){
			int top=k.front();
			int temp;
			k.pop();
			for(int j=0;j<ki-1;++j){
				temp=k.front();
				k.pop();
				dot[top].utov.push_back(temp);
				dot[top].utovl++;
				//cout<<"从"<<top<<"的第"<<i<<"条路线的站台到"<<temp<<"之间有边"<<endl;
				k.push(temp);
			}	
			k.push(top);
		}
		while(!k.empty()){
			k.pop();
		}
	}
	for(int i=1;i<=q;++i){
		cin >> x >> y;
		bfs(x,y);
		memset(vis,0,sizeof(vis));
	}
	
    return 0;
}
