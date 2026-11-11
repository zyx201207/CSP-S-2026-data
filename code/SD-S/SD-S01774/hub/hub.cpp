#include<bits/stdc++.h>
using namespace std;

const int maxn=1e3+10;

int c,t;
int n,k;

vector<int> vec[maxn];

struct node{
	int value,num;
}dis[maxn];

bool cmp(node x,node y){
	return x.value>y.value;
}

int find(int x,int step){
	step++;
	if(vec[x].size()==0) return step;
	for(int i=0;i<vec[x].size();i++){
		return find(vec[x][i],step);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			vec[x].push_back(y);
		}
		for(int i=1;i<=n;i++) dis[i].value=vec[i-1].size();
		sort(dis+1,dis+n+1,cmp);
		int ans=0;
		for(int i=1;i<=k;i++) ans=max(find(dis[i].num,0),ans);
		cout<<ans<<endl;
	}
	return 0;
}
