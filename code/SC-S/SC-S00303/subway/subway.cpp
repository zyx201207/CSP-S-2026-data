#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct node{
	int n;
	//int pi=-1;
	int d=0x3f3f3f3f;
	int vis;
	vector<int> l;
	vector<int> w;
	
};

class cmp{
public:
	bool operator()(const node& o1,const node& o2){
		return o1.d>o2.d;
	}
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> ent(m);
	vector<vector<int> > to(m);
	vector<vector<int> > w(m);
	vector<node> nodes(m);
	for(int i=0;i<m;i++){
		cin>>ent[i];
	}
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			nodes[tmp1-1].l.push_back(i);
			nodes[tmp1-1].w.push_back(tmp2);			
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j){
				//cout<<"0 ";
				continue;
			}
			int minw=0x3f3f3f3f;
			for(unsigned int k=0;k<nodes[i].l.size();k++){
				auto iter=find(nodes[j].l.begin(),nodes[j].l.end(),nodes[i].l[k]);
				if(iter!=nodes[j].l.end()){
					minw=min(minw,nodes[i].w[k]+nodes[j].w[iter-nodes[j].l.begin()]);
				}
			}
			if(minw==0x3f3f3f3f){
				
			}else{
				to[i].push_back(j);
				to[j].push_back(i);
				w[i].push_back(minw);
				w[j].push_back(minw);
			}
			//cout<<w[i][j]<<' ';
			
		}
		//cout<<'\n';
	}
	
	
	
	for(int t=0;t<q;t++){
		int s,l;
		cin>>s>>l;
		s--;
		l--;
		priority_queue<node,vector<node>,cmp> pq;
		for(unsigned int i=0;i<nodes.size();i++){
			nodes[i].d=0x3f3f3f3f;
			nodes[i].vis=0;
			//nodes[i].pi=-1;
			nodes[i].n=i;
		}
		
		nodes[s].d=0;
		
		pq.push(nodes[s]);
		while(!pq.empty()){
			node st=pq.top();
			pq.pop();
			int u=st.n;
			//cout<<u<<"!\n";
			if(st.vis)continue;
			st.vis=1;
			for(unsigned int e=0;e<to[u].size();e++){
				if(to[u][e]!=0){
					if(st.d+w[u][e]<nodes[to[u][e]].d){
						nodes[to[u][e]].d=st.d+w[u][e];
						//cout<<v<<' '<<nodes[v].d<<"!\n";
						pq.push(nodes[to[u][e]]);
						//nodes[v].pi=u;
					}
				}
			}
		}
		cout<<nodes[l].d+ent[l]+ent[l]<<'\n';
	}	
}