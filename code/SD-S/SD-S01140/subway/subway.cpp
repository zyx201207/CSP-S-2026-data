#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[1000086],a[1000086],x[1000086],t[10000086],tt[1000086],y[1000086],k[1086],l,vv[1000086];

struct jyz{
	int u,v,w;
};
vector<jyz> v[10000086];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]>>t[1]>>tt[1];
		for(int j=2;j<=n;j++){
			cin>>t[j]>>tt[j];
			for(int p=1;p<j;p++){
				v[++l].u=t[p];
				v[l].v=t[j];
				v[l].w=tt[p]+tt[j];
				v[++l].u=t[j];
				v[l].v=t[p];
				v[l].w=tt[p]+tt[j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		
	}
	
	return 0;
}
