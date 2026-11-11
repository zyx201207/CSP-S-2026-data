#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=1000005;
int c,n,m,d,q,w[maxN],k[maxN],a[1000][1000],t[1000][1000],x[maxN],y[maxN],ans;

bool zhida(int &x,int &y){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(x==a[i][j]){
				for(int z=1;z<=k[i];z++){
					if(y==a[i][j]) return true;
				}
			}
	
		}
	}
		return false;
}



int main(){
	freopen("subway.in ","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
				} 
				for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	//输入
		
	for(int i=1;i<=q;i++){//q次 
		ans+=w[x[i]]+w[y[i]]+t[x[i]][x[i]];//必须走 
		if(n==1||zhida){
		 ans+=t[x[i]][y[i]];
		cout<<ans;
	}
		
	}	
		
	
	
	
	
	
	
return 0;	
}



