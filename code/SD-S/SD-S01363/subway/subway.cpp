#include<bits/stdc++.h>
using namespace std;
using Piii=pair<int,pair<int,int>>;
const int M=5e5+5;
int c,n,m,d,q;//样例、地铁路数、地铁站数、最多经过的路线数、出行计划数。 

struct V{
	vector<int> e;
	int d=-1;
	int jinchu;
	int zhantai=0;
	int c;
}v[M];

priority_queue<Piii,vector<Piii>,greater<Piii> > que;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>v[i].jinchu;
	}
	
	for(int i=1,k,last=-1;i<=n;i++){
		cin>>k;
		for(int j=1,dot,w;j<=k;j++){
			cin>>dot>>w;
			v[dot].zhantai+=w;
			v[dot].c=i;
			if(last!=-1){
				v[dot].e.push_back(last);
				v[last].e.push_back(dot);
			}
			last=dot;
		}		 
	}
	
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		while(!que.empty()){
			que.pop();
		}
		que.push({0,{v[x].c,x}});
		for(;!que.empty();){
			Piii dian=que.top();
			que.pop();
			int dq=dian.second.second;
			if(v[dq].d==-1){
				v[dq].d=dian.first;
				for(int e:v[dq].e){
					if(v[e].c!=dian.second.first){
						que.push({v[dq].zhantai+ v[dq].d,{v[e].c,e}});
					}else{
						que.push({dian.first,{v[e].c,e}});
					}
				}
			}
		}
		cout<<v[y].d+v[x].zhantai+v[y].zhantai+v[x].jinchu+v[y].jinchu<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

