#include <bits/stdc++.h>
using namespace std;
struct f{
	int zhan;
	int piao;
}a[505][500005];
int c,n,m,d,q;
int b[500005];
struct s{
	int begin;
	int end;
}e[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j].zhan>>a[i][j].piao;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>e[i].begin>>e[i].end;
	}
	for(int i=1;i<=q;i++){
		int sum;
		for(int j=1;j<=n;j++){
			for(int w=1;w<=m;w++){
				sum+=a[j][w].piao;
			}
		}
		cout<<b[e[i].begin]+b[e[i].end]+sum;
	}
	return 0;
}
