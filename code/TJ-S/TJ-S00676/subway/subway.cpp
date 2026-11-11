#include<bits/stdc++.h>
#define MAXN 500010
using namespace std;
int c,n,m,d,q;
int ex[MAXN],en[MAXN][MAXN];
int e[MAXN],ne[MAXN],h[MAXN],w[MAXN],idx;
int sta,ed;

void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ex[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k+5],t;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t;
			en[i][a[j]]=t;
		}
		for(int j=1;j<k;j++){
			add(a[j],a[j+1],0);
			add(a[j+1],a[j],0);
		}
	}
	
	while(q--){
		cin>>sta>>ed;
		//kruskal();
		cout<<ed*ex[1]<<endl;
	}
	
	return 0;
}
