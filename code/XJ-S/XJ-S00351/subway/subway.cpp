#include <bits/stdc++.h>
using namespace std;
const int N=50000000;
long long sum=0,c,n,m,d,q,w[N],x[N],y[N],a[500][30000],t[500][30000],k[N];
long long jd(long long st,long long en){
	sum=sum+w[st]+w[en];
	return 0;
}
long long js(long long st,long long en,long long xian){
	int po=0;
	for(int j=1;j<=k[xian];j++){
		if(a[xian][j]==st)po++;
		if(a[xian][j]==en)po+=2;
	}
	if(po==0)js(st,en,xian+1);
	else if(po==1){
		for(int j=1;j<=k[xian];j++){
			for(int v=1;v<=n;v++){
				for(int g=1;g<=k[v];g++)
				if(a[xian][j]==a[v][g]){
					sum=sum+t[v][g]+t[xian][j];
					return js(a[v][g],en,v);
				}
			}
		}
	}
	else if(po==3)jd(st,en);
	return 0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		cin>>k[j];
		for(int i=1;i<=k[j];i++){
			cin>>a[j][i]>>t[j][i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		if(x[i]==y[i]){
			cout<<0<<'\n';
			continue;
			
		}
		js(x[i],y[i],1);
		jd(x[i],y[i]);
		cout<<sum<<'\n';
	}
}
