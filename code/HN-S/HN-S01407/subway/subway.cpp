#include<bits/stdc++.h>
using namespace std;
#define N 500005

int c,n,m,d,q;
int w[N],x[N],y[N];

struct sub{
	int k;
	int a[N];
	int t[N];
};

sub s[N];

int station[N];
int ansmin;
int ans;



int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","W",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].k;//经过的站点数 
		for(int j=1;j<=s[i].k;j++){//地铁线路经过的站点数据
			cin>>s[i].a[j]>>s[i].t[j];
			station[s[i].a[j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
//	while(q--){
//		ansmin+=w[x[q]]+w[y[q]];
//		
//		cout<<ansmin;
//	}
	return 0;
}















