#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ton[N];
int ca[N];
struct node{
	bool f;
	int pos;
}vis[N];
bool to[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ca[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) to[j]=1;
		vis[i].f=1,vis[i].pos=i;
		for(int j=i+1;j<=n;j++){
			if(vis[ca[j]].f==1) {
				for(int k=vis[ca[j]].pos;k<j;k++) to[k]=0;
				vis[ca[j]].pos=j;
			}else vis[ca[j]].f=1,vis[ca[j]].pos=j;
		}
		for(int j=1;j<=m;j++) vis[j].pos=0,vis[j].f=0;
		for(int j=i;j<=n;j++) if(to[j]==1) ton[ca[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<min(ton[i],m)<<" ";
	return 0;	
}
