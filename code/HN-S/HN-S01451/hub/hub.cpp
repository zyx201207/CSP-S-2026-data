#include<bits/stdc++.h>
using namespace std;
vector<int> edge[1000001];
bool flag[1000001],f,fl[1000001];
int spend[1000001],maxx=0,kuai=0,a[500001],used=0,ku,l;
int dfs(int u){
	int ans=0,s=0;
	for(int i=0;i<edge[u].size();i++){
	//cout<<u<<' '<<i<<' '<<edge[u][i]<<endl;//
		if(flag[edge[u][i]]==0){
			flag[edge[u][i]]=1;
			s=dfs(edge[u][i])+1;
			flag[edge[u][i]]=0;
			if(s>ans){
				ans=s;
			}
		}
	}
	return ans;
}
int dfs_(int u,int s){
	if(fl[u]==1&&s!=0){
		return s;
	}
	int ans=0;
	for(int i=0;i<edge[u].size();i++){
		if(flag[edge[u][i]]==0){
			flag[edge[u][i]]=1;
			if(fl[u]==0){
				s=dfs_(edge[u][i],s+1);
			}else{
				s=dfs_(edge[u][i],s);
			}
			flag[edge[u][i]]=0;
			if(s!=0){
				break;
			}
		}
	}
	return s;
}
int dfs__(int u,bool s){
	if(fl[u]==1&&s!=0){
		fl[u]=1;
		return 1;
	}
	int ans=0;
	for(int i=0;i<edge[u].size();i++){
		if(flag[edge[u][i]]==0){
			flag[edge[u][i]]=1;
			if(fl[u]==0){
				s=dfs_(edge[u][i],s+1);
			}else{
				s=dfs_(edge[u][i],s);
			}
			flag[edge[u][i]]=0;
			if(s!=0){
				break;
			}
		}
	}
	if(s!=0){
		fl[u]=1;
	}
	return s;
}
void kua(){
	ku=used;
	for(int i=1;i<=used;i++){
		for(int j=0;j<edge[a[i]].size();i++){
			if(fl[edge[a[i]][j]]==1&&edge[a[i]][j]<a[i]){
				ku--;
			}
		}
	}
	return;
}
void lu(){
	l=0;
	for(int i=1;i<=used;i++){
		for(int j=0;j<edge[a[i]].size();i++){
			if(fl[edge[a[i]][j]]==1&&edge[a[i]][j]<a[i]){
				
			}else{
				l=dfs_(a[i],0);
			}
		}
	}
} 
void lu_(){
	l=0;
	for(int i=1;i<=used;i++){
		for(int j=0;j<edge[a[i]].size();i++){
			if(fl[edge[a[i]][j]]==1&&edge[a[i]][j]<a[i]){
				
			}else{
				l=dfs__(a[i],0);
			}
		}
	}
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,k,u,v;
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for(int j=1;j<=n;j++){
			flag[j]=1;
			spend[j]=dfs(j);
			flag[j]=0;
			//cout<<spend[j]<<endl;//
			if(spend[j]>maxx){
				maxx=spend[j];
			}
		}
		while(f=0&&used<k){
			f=1;
			for(int j=1;j<=n;j++){
				if(spend[j]==maxx){
					f=0;
					used++;
					a[used]=j;
					fl[j]=1;
					kua();
					if(ku==2){
						lu();
						if(k-used>=l){
							used+=l;
							lu_();
						}else{
							break;
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				flag[j]=1;
				spend[j]=dfs(j);
				flag[j]=0;
				if(spend[j]>maxx){
				maxx=spend[j];
				}
			}
		}
		cout<<maxx<<endl;
	}//0 2 5 2 1 2 2 3 3 4 4 5 10 3 1 2 1 3 2 4 2 5 3 6 3 7 3 8 7 9 9 10
	return 0;
}
