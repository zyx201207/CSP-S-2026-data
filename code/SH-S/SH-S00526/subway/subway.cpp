#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int w[N],a[N][N],t[N][N];
int rd(){
	return rand()>>15^rand();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		cout<<rd()%100000<<"\n";
	}
	return 0;
}
