#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int N=1010;
int c,n,m,d,q;
int w[N],k[N],dis[N][N];
struct edge{
	int a,t;
}a[N];
vector<int>ve[N];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j].a>>a[j].t;
			ve[a[j].a].push_back(i);
		}
	}
	
	return 0;
}
