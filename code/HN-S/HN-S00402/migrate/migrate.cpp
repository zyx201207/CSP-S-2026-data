#include<bits/stdc++.h>
using namespace std;
int c,t;
int ct=0;
const int N=5e5+5;
struct node{
	long long w;
	vector<int> to;
}x[N];
long long ans=1e9;
long long cnt=0;
void dfs(int st,int ed,int pos,long long step){
	if(pos==st){
		ans=1e9;
		cnt=0;
	}
	if(pos>ed){
		return;
	}
	if(pos==ed){
		
		if(step==ans){
			cnt++;
		}
		else{
			ans=min(ans,step);
			cnt=1;
		}
		
		return;
	}

	for(int i=0;i<x[pos].to.size();i++){
		dfs(st,ed,x[pos].to[i],step+1);
	}
}
int main(){
	freopen("migrate,in","r",stdin);
	freopen("migrate,out","w",stdout);
	cin>>c>>t;
	while(t--){
		ct=0;
		long long ans=1e9;
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i].w;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i].w-x[j].w)<=d){
					x[i].to.push_back(j);
				}
			}
		}
		ct=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				dfs(i,j,i,0);
				if(cnt==2){
					ct++;
				}
				cnt=0;
				ans=1e9;
			}
		}
		cout<<ct<<endl;
		ct=0;
	}
	return 0;
}
