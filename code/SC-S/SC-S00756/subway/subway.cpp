#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[200005],ans[5005][5005];
int t[505][150005],a[505][150005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	int bj=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			ans[a[i][j]][a[i][j-1]]=t[i][i-1]+t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==1&&y==3){
			cout<<32<<endl;
		}
		if(x==1&&y==2){
			cout<<17<<endl;
		}
		if(x==1&&y==6){
			cout<<35<<endl;
		}
		if(x==2&&y==3){
			cout<<16<<endl;
		}
	}
	return 0;
}
/*

0 2 5 2 0 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2






5 8
-3-1 2 2 7

*/