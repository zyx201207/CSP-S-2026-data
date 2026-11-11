#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
long long c,n,m,d,q,a[N],s[505][N],w[505][N],l,r; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int f=0;
		cin>>f;
		for(int j=1;j<=f;j++) cin>>s[i][j]>>w[i][j];
	}
	while(q--){
		cin>>l>>r;
		
	}
	return 0;
}
