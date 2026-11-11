#include<bits/stdc++.h>
using namespace std;
//O(n^2) 
int stk[1000005],a[1000005];//Manual Stack
bool vis[1000005];//Add
int c[1000005];
unordered_map<int,int> latest;//To find i=[1..m] 
int main(){
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];//Start 1,end n
	}
	for(int i=1;i<=n;i++){
		latest.clear();
		memset(vis,0,sizeof(vis));
		int stkend=1;//Stack: [1,stkend]
		int start=i;//Skipped [1,i)
		for(int j=start;j<=n;j++){
			if(latest.find(a[j])!=latest.end()){
				stkend=latest[a[j]];
				unordered_map<int,int> newl;
				for(auto &s:latest){
					if(s.second<=stkend){
						newl[s.first]=s.second;
					}
				}
				latest=newl;
			}else{
				stk[++stkend]=a[j];
				latest[a[j]]=stkend;
			}
		}
		for(int j=1;j<=stkend;j++){
			if(!vis[stk[j]]){
				c[stk[j]]++;
				vis[stk[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	fclose(stdin);fclose(stdout);
	return 0; 
}
