#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],b[N];
int dfs(int u,int v,int s){
	if(s==0){
		if(u==v){
			return 1;
		}else{
			return 0;
		}
	}
	int ans=0;
	for(int i=u+1;i<=b[u];i++){
		ans+=dfs(i,v,s-1);
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	t=1;
	while(t--){
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		cout<<a[n]-a[1]<<"\n";
		if(a[n]-a[1]<=d){
			cout<<0<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-d>a[i]){
						b[i]=j-1;
						break;
					}
				}
				if(b[i]==0){
					b[i]=n;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<' ';
//		}
//		cout<<'\n';
		int ans=0;
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				if(b[u]>=v){
					continue;
				}else{
					int step=0,x=u;
					while(x<v){
						step++;
						x=b[x];
					}
//					cout<<u<<"->"<<v<<"min:"<<step<<'\n';
					if(step==0){
						continue;
					}else{
						int p=dfs(u,v,step);
//						cout<<u<<"->"<<v<<":"<<p<<'\n';
						if(p==2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}