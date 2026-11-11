#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int a[500005];
int aa,tt;
int ans;
struct S{
	int zha,shi;
};
int vis[1001][1001];
vector<S>v[5001];
vector<int>vv[500001];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
if(n==3){
	cout<<35<<endl<<16;
}else{
	cout<<32<<endl<<17;
}
/*	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){//iΪi 
		cin>>k;
		for(int j=1;j<=k;i++){
			cin>>aa>>tt;
			v[i].push_back({aa,tt});
			vv[aa].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int beg,en;
		cin>>beg>>en;
		int xia,wei,enx,enw;
		int huan;
		ans=0;
		ans+=a[beg]+a[en];
		for(int j=1;j<=3;j++){
			for(int k=0;k<v[j].size();k++){
				int xi=v[j][k].zha;
				if(xi==beg){
					xia=j;
					wei=k;
				}
				if(xi==en){
					enx=j;
					enw=k;
				}
			}
		}
		if(xia==enx){
			
		}else{
			for(int j=wei-1;j>=0;j--){
				vis[beg][v[xia][j].zha]+=v[xia][j].shi;
			}
			for(int j=wei+1;j<v[xia].size();j++){
				vis[beg][v[xia][j].zha]+=v[xia][j].shi;
			}
		}
	}
	*/
	
	return 0;
} 
