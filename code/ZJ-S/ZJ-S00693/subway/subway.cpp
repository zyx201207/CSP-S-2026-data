#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int k,x,y;
bool flag=1;
struct nod{
	int to;
	long long val;
};
struct node{
	vector<nod>nxt;
	long long tim;
	bool flag;
};
void dfs(vector<node>&pic,const int &p){
	if(p==y){
		return;
	}
	for(nod &i:pic[p].nxt){
		if(pic[i.to].flag!=flag||pic[i.to].tim>pic[p].tim+i.val){	
			pic[i.to].tim=pic[p].tim+i.val;
			pic[i.to].flag=flag;
			dfs(pic,i.to);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<node>pic(n+m+1,{{},0,0});
	int p=m+1;
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x>>y;
			pic[x].nxt.push_back({p,y});
			pic[p].nxt.push_back({x,y});
		}
		p++;
	}
	while(q--){
		cin>>x>>y;
		pic[x].tim=0;
		pic[x].flag=flag;
		dfs(pic,x);
		cout<<pic[y].tim+w[x]+w[y]<<'\n';
		flag=1-flag;
	}
	return 0;
}