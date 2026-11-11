#include <bits/stdc++.h>
using namespace std;
struct li{
	int k;
	long long station[500005];
	int time[500005];
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	int sta[m+1];
	for(int i=1;i<=n;i++){
		cin>>sta[i];
	}
	li line[n+1];
	vector<int> a[m+1];
	vector<int> change;
	for(int i=1;i<=n;i++){
		cin>>line[i].k;
		for(int j=1;j<=line[j].k;j++){
			cin>>line[i].station[j]>>line[i].time[j];
			a[line[i].station[j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].size()!=0){
			change.push_back(i);
		}
	}
	int s,t;
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		int ans=sta[s]+sta[t];
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int temp=q.front();
			for(int v:a[temp]){
			} 
		} 
	}
	return 0;
}
