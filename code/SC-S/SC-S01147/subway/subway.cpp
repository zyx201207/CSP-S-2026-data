#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500010];
ll a[50010][50010],t[50010][50010];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=3;i<=2+n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j]; 
		}
	}
	while(q--){
		int s,s1;
		cin>>s>>s1;
		
	}
	return 0;
}