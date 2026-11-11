#include<bits/stdc++.h>
using namespace std;
int c,d,n,m,q,chu[20005];
vector<pair<int,int> >e[505],w[20005];
int a[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subsay.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>chu[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e9*(i!=j);
		}
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		while(p--){		
			int l,r;
			cin>>l>>r;
			e[i].push_back(make_pair(l,r));
			w[l].push_back(make_pair(i,r));
		}
	}
	for(int i=1;i<=n;i++){
		for(auto p:e[i]){
			int z=p.first,y=p.second;
			for(auto g:w[z]){
				int x=g.first,o=g.second;
				a[x][i]=a[i][x]=min(a[x][i],o+y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&j!=k&&i!=k)a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[j][k]);
			}
		}
	}
	while(q--){
		int l,r,mi=1e9;
		cin>>l>>r;
		for(auto p:w[l]){
			int z=p.first,y=p.second;
			for(auto g:w[r]){
				int x=g.first,o=g.second;
				if(x!=z)mi=min(mi,a[x][z]+o+y);
				else{
					mi=min(mi,o+y);
				}
			}
		}
		cout<<mi+chu[l]+chu[r]<<"\n";
	}
	return 0;
}
//store:68 O(m*n^2)
/*
//	freopen("subway.in","r",stdin);
//	freopen("subsay.out","w",stdout);
luogu v50 ccf

wo yao shang mi huo xing wei da shang!

deng wo kao wan gei da jia mo xie zhui yi!
-by luogu user _HWT_(zhi yi) on 1.27h
 
 xiong da
 **
 ()
 |
---
/\ 
 xiong er
 **
 ()
 |
---
/\

guang tou qiang bu yao ju wo de shu!!!!!(hao ba qi shi shi yi zhang tu) 
*/
