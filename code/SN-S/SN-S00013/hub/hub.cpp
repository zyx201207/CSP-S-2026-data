#include<bits/stdc++.h>
using namespace std;
const int M=510;
const int Ki=5e5+10;
const int Q=1e5+10;
int c,m,n,d,q;
int w[M];
vector<int> e[M];
struct{
	int f,t;
}b[Q];
struct{
	int num,time;
}a[M][Ki];
int dp[M][M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[0][i];
		for(int j=1;j<=a[0][1].num;j++){
			cin>>a[j][i].num>>a[j][i].time;
			e[a[j][i].num].push_back(i);
			
		}
	}
	for(int i=1;i<=q;i++) cin>>b[i].f>>b[i].t;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;i<=d;i++){
				e[i]
			}
		}
	}
}
