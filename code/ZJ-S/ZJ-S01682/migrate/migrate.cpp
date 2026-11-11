#include<bits/stdc++.h>//WA
using namespace std;
int n,d;
vector<int> x;
vector<bool> visit;
vector<vector<int> > memo;
int dfs(int p,int st,int en){
	if(p==en)return 1;
	if(memo[st][p]!=-1)return memo[st][p];
	int l=p,r=p;
	while(l>=0){
		if(x[l]<x[p]-d)break;
		else l--;
	}
	while(r<=n){
		if(x[r]>x[p]+d)break;
		else r++;
	}
	l++;
	r--;
	int ans=1;
	for(int i=l;i<=r;i++){
		if(!visit[i]){
			visit[i]=1;
			ans+=dfs(i,p,en)*dfs(i,st,p);
			visit[i]=0;
		}
	}
	memo[st][en]=ans;
	memo[en][st]=ans;
	return ans;
}
bool check(int st,int en){
	visit.clear();
	visit[st]=1;
	if(dfs(st,st,en)==2)return 1;
	else return 0;
}
void work(){
	cin>>n>>d;
	x.resize(n+1);
	visit.resize(n+1);
	x.clear();
	memo.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i];
		memo[i]=vector<int>(n+1,-1);
	}
	sort(x.begin(),x.end());
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j))cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
