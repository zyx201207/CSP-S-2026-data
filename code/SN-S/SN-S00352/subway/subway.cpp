//刘泰豫 SN-S00352 西安市第一中学
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],ans=0,ka[505][500005],kb[505][500005],k[505];
//struct sy{
//	long long k1;
//} ;
void dfs(long long x,long long y,long long ans1){
	if(x==y){
		ans=max(ans,ans1);
		return;
	}for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			if(i==x){
				dfs(ka[i][j],y,ans+kb[i][j]);
			}else return;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[m];
	}for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>ka[i][j]>>kb[i][j];
		}
	}for(int i=0;i<q;i++){
		long long a,b;
		cin>>a,b;
		dfs(a,b,w[a]+w[b]);
		cout<<ans<<endl;
	}return 0;
}
