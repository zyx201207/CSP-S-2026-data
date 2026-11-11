#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,x[2000006];

bool check(int u,int v){
	for(int i=u;i<v;++i){
		for(int j=i+2;j<=v;++j){
			if(j-i>1&&x[j]-x[i]>=2*d){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans+=check(i,j);
			}
		}
		cout<<ans<<'\n';
	}
}
