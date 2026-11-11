#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,s,e;
}N[1000000];
int n,m;
bool vis[10000000];
int num[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		N[x].a=x;
		if(vis[x]==false){
			num[x]=i;
			N[x].s=i;
			N[x].e=i;
			vis[x]=true;
		}
		else{
			N[x].e=i;
			num[x]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=N[i].s+1;j<=N[i].e-1;j++){
			num[N[j].a]--;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}


