#include<bits/stdc++.h>
using namespace std;
struct o___{
	bool h;
	int w;
	int ans;
};
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	o___ a_[m+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int g[n+1]={};
	int node=0;
	for(int i=1;i<=n;i++){
		int g[n+1]={};
		for(int j=i;j<=n;j++){
			if(a_[j].h){
				for(int f=a_[j].w;f<=node;f++){
					a_[g[f]].h =false;
					g[f]=0;
				}
				node=a_[j].w-1;
			}
			node++;
			g[node]=a[j];
			a_[j].h=true;
			a_[j].w=node;
		}
		for(int j=1;j<=m;j++){
			if(a_[j].h){
				 a_[j].ans++;
				 cout<<i<<' '<<j<<endl;
			}
			a_[j].h=false;
			a_[j].w=0;
		}
		for(int q=1;q<=node;q++) cout<<g[q]<<' ';
		node=0;
	}
	for(int i=1;i<=m;i++){
		cout<<a_[i].ans<<' ';
	}
	return 0;
} 
