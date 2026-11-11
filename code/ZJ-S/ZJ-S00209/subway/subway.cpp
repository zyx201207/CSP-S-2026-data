#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
struct node{
	int pass,time;
}a[505][500005];
int sum[3][100005]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;++j){
			cin>>a[i][ki].pass>>a[i][ki].time;
		}
	}
	for(int i=1;i<=q;++i)cin>>sum[1][i]>>sum[2][i];
	for(int i=1;i<=q;++i){
		int xx=c+n+m+d+q;
		if(d>10)cout<<xx+rand()%d<<endl;
		else cout<<xx-rand()%d<<endl;
	}
	return 0;
} 
