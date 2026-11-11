#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,x,y,xxs,yxs;
ll w[500010],k[510],t[500010][510],xx[510],yx[510];
bool hcz[500010][510],l;
ll findxy(ll x,ll xxs,ll y){
	for(int i=1;i<=xxs;i++){
		for(int j=1;j<=k[i];j++){
			return t[x][i]+t[j][i]+t[y][i];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int sdf;
		for(int j=1;j<=k[i];j++){
			cin>>sdf;
			hcz[sdf][j]=1;
			cin>>t[j][i];
		}
	}
	ll su;
	while(q--){
		su=0;
		xxs=0;
		yxs=0;
		l=0;
		cin>>x>>y;
		su+=(w[x]+w[y]);
		for(int i=1;i<=n;i++){
			if(hcz[x][i]==1&&hcz[y][i]==1){
				su+=(t[x][i]+t[y][i]);
				l=1;
				break;
			}
			if(hcz[x][i]==1){
				xx[++xxs]=i;
			}
			if(hcz[y][i]==1){
				yx[++yxs]=i;
			}
		}
		if(l){
			cout<<su<<endl;
			continue;
		}
		su+=findxy(x,xxs,y);
		cout<<su<<endl;
	}
	return 0;
} 
