#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v,v2;
int s[300005],h[300005];
void dfs(int d){
	v2=v;
	for(int i=d;i<n;i++){
		h[v2[i]]+=1;
		if(h[v2[i]]>1){
			for(int u=i-1;u>=d;u--){
				if(v2[u]==v2[i]){
					v2[u]=0;
					h[v2[i]]-=1;
					break;
				}
				h[v2[u]]-=1;
				v2[u]=0;
			}
			
		}
	}
	for(int i=d;i<n;i++){
		//cout<<v2[i]<<' ';
		s[v2[i]]++;
	}
	for(int i=0;i<=m;i++){
		h[i]=0;
	}
	//cout<<endl;
	return ;
}
void d1(){
	for(int i=0;i<n;i++){
		h[v[i]]++;
	}
	s[1]=h[v[1]];
	for(int i=2;i<=m;i++){
		s[i]=s[i-1]+h[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mx=1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		if(v.size()!=1)
		mx=mx*(x>=v[i-1]);
	}
	if(mx==1){
		d1();
	}
	else{
		for(int i=0;i<n;i++){
			dfs(i);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
