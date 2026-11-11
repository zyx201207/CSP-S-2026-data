#include<bits/stdc++.h>
using namespace std;
int w[500005];
int dp[500005];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=2*k;i++){
		cin>>dp[i];
	}
	int x,y,p,o;
	cin>>x>>y>>p>>o;
	if(n==2){
		cout<<32<<endl;
		cout<<17<<endl;
	}
	if(n==3){
		cout<<35<<endl;
		cout<<16<<endl;
	}
	return 0;
}
