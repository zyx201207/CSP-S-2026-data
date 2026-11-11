#include<bits/stdc++.h>
using namespace std;
struct edge{
	int value,arrive;
};
struct point{
	vector<edge*>path;
	int v;
};
bool cmp(edge* a,edge* b){
	return a->value>=b->value;
}
vector<point*>station;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		point* sta=new point();
		station.push_back(sta); 
		cin>>station[i]->v;
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int a[k],t[k];
		for(int j=0;j<k;j++){
			cin>>a[j]>>t[j];
		}
		for(int x=0;x<k;x++){
			for(int y=0;y<k;y++){
				if(x==y){
					continue;
				}
				edge* e=new edge();
				e->value=t[x]+t[y];
				e->arrive=a[y];
				station[a[x]-1]->path.push_back(e);
			}
		}
	}
	while(q--){
		int start,end;
		cin>>start>>end;
		start--;
		end--;
		vector<edge*>path;
		for(int i=0;i<station[start]->path.size();i++){
			edge* ed =new edge();
			ed=station[start]->path[i];
			path.push_back(ed);
		}
		sort(path.begin(),path.end(),cmp);
		int aans[m];
		bool used[m];
		for(int i=0;i<m;i++){
			used[i]=false;
			aans[i]=0;
		}
		used[start]=true;
		while(!path.empty()){
			if(used[path[path.size()-1]->arrive-1]==true){
				path.pop_back();
				continue;
			}
			aans[path[path.size()-1]->arrive-1]=path[path.size()-1]->value;
			//cout<<path[path.size()-1]->arrive-1<<" "<<aans[path[path.size()-1]->arrive-1]<<endl;
			used[path[path.size()-1]->arrive-1]=true;
			int nxtsta=path[path.size()-1]->arrive-1;
			int idx=path.size()-1;path.pop_back();
			for(int i=0;i<station[nxtsta]->path.size();i++){
				edge* ed=new edge();
				ed->arrive=station[nxtsta]->path[i]->arrive;
				ed->value=station[nxtsta]->path[i]->value;
				ed->value+=aans[nxtsta];
				path.push_back(ed);  
			}
			sort(path.begin(),path.end(),cmp);
			/*
			for(int i=0;i<path.size();i++){
				cout<<path[i]->value<<" "<<path[i]->arrive<<endl;
			}*/
		}
		int ans=aans[end]+station[end]->v+station[start]->v;
		cout<<ans<<endl;
	}
}
