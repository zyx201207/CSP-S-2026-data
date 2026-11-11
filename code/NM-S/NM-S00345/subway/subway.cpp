#include<bits/stdc++.h>
using namespace std;

int n,m,c,d,q;
const int N=2001;
int a[N][N],t[N][N],w[N];
int p[N];

//int find(int x){
//	if(x!=p[x]) return p[x]=find(p[x]);
//	else return x;
//}

int main(){
	
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;i<=k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i=50;i++){
		for(int j=0;j<=50;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i=50;i++){
		for(int j=0;j<=50;j++){
			cout<<t[i][j]<" ";
		}
		cout<<endl;
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		
	}
	return 0;
} 
