#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,ans;
int w[500010],t[510][500010],t0,x,y;
bool f1,f2;
void solveB(){
	ans=0;
	ans+=w[x];
	ans+=w[y];
	ans+=t0*2;
	cout<<ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2)f1=1;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t[i][a];
			if(i==1&&j==1)t0=t[i][a];
			else{
				if(t[i][a]!=t0)f2=1;
			}
		}
	}
	while(q--){
		cin>>x>>y;
			solveB();
		
	}
	
	
	return 0;
} 