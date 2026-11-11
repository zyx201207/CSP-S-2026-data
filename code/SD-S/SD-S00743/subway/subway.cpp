#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,k,tot=-1,sum[N],w[N],a[N],t[N],x[N],y[N],head[N],ver[2*N],Next[2*N];
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		for(int i=1;i<=k;i++){
			if(i==k){
				add(a[k],a[1]);
			}
			else{
				add(a[i],a[i+1]);
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		sum[i]+=w[x[i]]+w[y[i]]-t[x[i]]-t[y[i]];
		for(int j=1;j<=k;j++){
			sum[i]+=t[j]*2;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<sum[i]<<"\n";
	}
	return 0;
}
