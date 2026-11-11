#include<bits/stdc++.h>
using namespace std;
int l,r;
int minn=INT_MAX;
struct node{
	int sta;
	int mi;
}bus[1000][1000];
int tim[500005];
int c,n,m,d,q;
int v[500005];
int g[500005];
void zhan(int h,int t){
	if(h==r){
		if(t+tim[h]<minn){
			minn=t+tim[h];
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(g[i]==1) continue;
		for(int j=1;j<=n;j++){
			if(bus[i][j].sta==h){
				v[j]=1;
				t+=bus[i][j].mi;
				for(int k=1;k<=n;k++){
					if(k==0) break;
					if(v[k]==1) continue;
					g[i]=1;
					zhan(bus[i][k].sta,t+bus[i][k].mi);
					g[i]=0;
				}
				v[j]=0;
				continue;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>bus[i][j].sta>>bus[i][j].mi;
		}
	}while(q--){
		cin>>l>>r;
		zhan(l,tim[l]);
		cout<<minn<<endl;
		minn=INT_MAX;
	}
	return 0;
}
