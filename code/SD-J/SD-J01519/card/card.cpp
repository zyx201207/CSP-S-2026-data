#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=3000;
#define int long long
int n,m,a[N],T[M];
bool in_place[N][M];
void place_card(int x){
	memset(in_place,0,sizeof(in_place));
	map<int,int> last;
	in_place[x][a[x]]=1;
	last[a[x]]=1;
	for(int i=x+1;i<=n;i++){
		in_place[i][a[i]]=1;
		for(int j=1;j<=m;j++) if(j!=a[i]) in_place[j][i]=in_place[j][i-1];
		if(last.find(a[i])!=last.end()){
			int last_ai=last[a[i]];
			for(int j=1;j<=m;j++){
				if(a[i]!=j && last.find(j)!=last.end() && last[j]>last_ai){
					in_place[j][i]=0;
					cout<<j<<'\n';
				}
			}
		}
		last[a[i]]=i;
	}
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++){
		place_card(j);
		for(int i=1;i<=m;i++) T[i]+=in_place[i][n];
	}
	for(int i=1;i<=m;i++) cout<<T[i]<<' ';
	return 0;
}
