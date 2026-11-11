#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,a[500001],dp[300001],v[300001],r[300001],g[300001],ta[300001],tn,c[300001];
void tsort(){
	queue<int> q;
	for(int i=1;i<=m;i++){
		if(r[i]==0){
			q.push(i);
		}
	}
	while(q.size()){
		int t=q.front();
		ta[tn++]=t;
		q.pop();
		r[g[t]]--;
		if(r[g[t]]==0){
			q.push(g[t]);
		}
	}
}
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	v[a[n-1]]=1;
	for(int i=n-2;i>=0;i--){
		if(v[a[i]]==0){
			v[a[i]]=1;
			g[a[i]]=a[i+1];
			r[a[i+1]]++;
		}
	}
	tsort();
	for(int i=0;i<tn;i++){
		dp[ta[i]]+=c[ta[i]];
		dp[g[ta[i]]]+=dp[ta[i]];
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<' ';
	}
	return 0;
}
