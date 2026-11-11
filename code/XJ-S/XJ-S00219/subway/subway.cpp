#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 505;
int a[M];
int b[M][M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int id,w;
			cin>>id>>w;
			b[i][id] = w;
		} 
	}
	for(int i = 1;i<=p;i++){
		int s,e,mi = INF;
		cin>>s>>e;
		for(int j = 1;j<=n;j++){
			if(b[j][s]!=0 &&b[j][e]!=0){
				mi = min(a[s]+a[e]+b[j][s]+b[j][e],mi);
			}
		}
		cout<<mi<<"\n";
	}
	return 0;
} 
