#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{int a,t;};
int w[50001];
int used[50001];
int sub[50001][501];
int sta[501][50001];
p arr[501][50001];
int minn;
void dfs(int x,int y,int step){
	if (x==y){
		minn=min(minn,step);
	}
	for (int i=1;i<=sub[x][0];i++){
		for (int j=1;j<=arr[ sub[x][i] ][0].a;j++){
	    	if (step>=minn){return ;}
	    	if (used[ arr[ sub[x][i] ][j].a ]){continue;}
	    	used[ arr[ sub[x][i] ][j].a ]=1;
	    	dfs(arr[ sub[x][i] ][j].a,y,step+arr[ sub[x][i] ][ sta[ sub[x][i] ][x] ].t+arr[ sub[x][i] ][j].t);
	    }
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){cin>>w[i];}
    for (int i=1;i<=n;i++){
    	cin>>arr[i][0].a;
    	for (int j=1;j<=arr[i][0].a;j++){
    		cin>>arr[i][j].a;
    		cin>>arr[i][j].t;
    		sub[arr[i][j].a][j]=i;
    		sub[arr[i][j].a][0]++;
    		sta[i][arr[i][j].a]=j;
		}
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        minn=INT_MAX;
        dfs(x,y,0);
        cout<<minn;
	}
	return 0;
}
