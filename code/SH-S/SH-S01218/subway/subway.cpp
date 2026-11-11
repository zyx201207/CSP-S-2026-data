#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,M=5e4+9;
ll c,n,m,d,q;
ll w[M];
ll k[N];
ll a[N][M];
ll t[N][M];
struct node{
	ll v,val;
};
vector<node> to[N];
void add(ll aa,ll bb,ll cc){
	to[aa].push_back({bb,cc});
	to[bb].push_back({aa,cc});
	return ;
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			add(a[i][j],a[i][j+1],0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=1;l<=k[i];l++){
				for(int r=1;r<=k[j];r++){
					if(a[i][l]==a[j][r]){
						ll cc=t[i][l]+t[j][r];
						if(r!=n)add(a[i][l],a[j][r+1],cc);
						if(r!=1)add(a[i][l],a[j][r-1],cc);
						if(l!=1)add(a[i][l-1],a[j][r],cc);
						if(l!=n)add(a[i][l+1],a[j][r],cc);
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<to[i].size();j++){
			cout<<i<<" "<<to[i][j].v<<" "<<to[i][j].val<<endl;
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
