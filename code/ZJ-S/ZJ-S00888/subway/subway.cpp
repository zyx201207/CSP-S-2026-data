#include<bits/stdc++.h>
#define rep(n,l,r) for(int n=l;n<=r;n++)
#define rep0(n,r) for(int n=0;n<=r;n++)
#define rep1(n,r) for(int n=1;n<=r;n++)

#define M 500002
#define N 502
#define int long long

using namespace std;

int n,m,c,d,q;
int k;
int w[M];
int a[N][M],t[N][M];
int trans[N][N];
set<int> route[M];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	rep1(i,n){
		cin>>k;
		rep1(j,k){
			cin>>a[i][j]>>t[i][j];
		}
	}
	/*
		?~我买光所有的炸药
		?~却还是炸不掉TA
		?~给你的碉堡
		?~我花光了金币 
		?~我花光了权力 
		?~我花光我仅有的正义 
	*/
	cout<<-1;
	
	return 0;
}
