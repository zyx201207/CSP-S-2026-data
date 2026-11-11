#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,l[1000010];
vector<int>tree[1000010];
vector<int> needprint;
int dfs(int x,int fa){
	int ans=l[x];
	if(l[fa]&&ans)ans--;
	for(int i=0;i<tree[x].size();i++){
		if(tree[x][i]==fa)continue;
		ans+=dfs(tree[x][i],x);
	}
//	cout<<"(^^)"<<v[x]<<' '<<ans<<endl;
	return ans;
}
int dfs2(int x,int fa,int step){
	if(l[x])return step;
	int sum=1000000010;
	for(int i=0;i<tree[x].size();i++){
		if(tree[x][i]==fa)continue;
		sum=min(sum,dfs2(tree[x][i],x,step+1));
	}
	return sum;
}
void remain(){
	int ans=1000000010;
	cin>>n>>k;
	for(int i=1;i<=n;i++)tree[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	for(int i=1;i<int(pow(2,n));i++){
		memset(l,0,sizeof(l));
		int t=i,j=1,an=0,nans=0;
		while(t){
			if(t%2){
				l[j]=1;
				an++;
			}
			j++;
			t/=2;
		}
		if(an!=k)continue;
		if(dfs(1,1)>2)continue;
		for(int w=1;w<=n;w++)
			if(!l[w]){
				nans=max(nans,dfs2(w,0,0));
//				cout<<dfs2(w,0,0)<<endl;
			}
//		cout<<endl;
		ans=min(ans,nans);
	}
	needprint.push_back(ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)remain();
	for(int i=0;i<needprint.size();i++)cout<<needprint[i]<<endl;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
