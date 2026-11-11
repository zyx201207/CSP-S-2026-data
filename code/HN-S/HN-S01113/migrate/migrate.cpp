#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

const int MAX_isl=2e6+5;

long long int junk;
long long int task;
long long int isla;
long long int most;
long long int fans;

long long int ipos[MAX_isl];

struct way{
	long long int pass;
	long long int nowp;
};

struct each_node{
	long long int mind;
	long long int ways;
};
each_node eano[MAX_isl];

vector <long long int> grph[MAX_isl];

queue <way> tree;

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>junk;
	cin>>task;
	
	while(task--){
		//cout<<"task_new______"<<endl;
		
		fans=0;
		
		cin>>isla;
		cin>>most;
		
		memset(ipos,0,sizeof(ipos));
		memset(grph,0,sizeof(grph));
		
		for(long long int i=1;i<=isla;i++)				//岛屿位置 
			cin>>ipos[i];
		
		for(long long int u=1;u<=isla;u++){				//处理岛屿可达性 
			for(long long int v=u+1;v<=isla;v++)	
				if(ipos[v]-ipos[u]<=most)	
					grph[u].push_back(v);
		}
		
		for(long long int u=1;u<isla;u++){				//对于不同的起始岛屿 
			
			for(long long int i=1;i<=isla;i++){
				eano[i].mind=0;
				eano[i].ways=0;
			}
			
			for(long long int i=u;i<=isla;i++)
				eano[i].mind=MAX_isl;
				
			way iponeer;
			iponeer.nowp=u;
			iponeer.pass=0;
			tree.push(iponeer);
			
			while(!tree.empty()){
				
				way current=tree.front();
				tree.pop();
				
				if(eano[current.nowp].mind<current.pass)
					continue;
				else if(eano[current.nowp].mind=current.pass)
					eano[current.nowp].ways++;
				else if(eano[current.nowp].mind>current.pass){
					eano[current.nowp].mind=current.pass;
					if(current.nowp!=u)
						eano[current.nowp].ways=1;
					else
						eano[current.nowp].ways=0;
				}
				
				for(long long int i=0;i<grph[current.nowp].size();i++){
					way next;
					next.nowp=grph[current.nowp][i];
					next.pass=eano[current.nowp].mind+1;
					tree.push(next);
				}
			}
			
			for(long long int i=u+1;i<=isla;i++){
				//cout<<i<<" "<<eano[i].mind<<" "<<eano[i].ways<<endl;
				if(eano[i].ways==2)
					fans++;
			}
		}
		
		cout<<fans<<endl;
	}
	return 0;
}
