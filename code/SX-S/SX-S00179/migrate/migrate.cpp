#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[6005],m[6005],g[6005],ans;
queue<long long>eq;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}ans=0;
		for(int i=1;i<=n;i++){
			long long llmx=LONG_LONG_MAX;
			for(int j=1;j<=n;j++){
				m[j]=llmx;g[j]=0;
			}
			m[i]=0;
			queue<long long>qx=eq,qm=eq;
			qx.push(i);qm.push(0);
			while(!qx.empty()){
				int id=qx.front();qx.pop();
				int jl=qm.front();qm.pop();
				for(int j=id+1;x[j]-x[id]<=d&&j<=n;j++){
					if(jl+1<=m[j]){
						qx.push(j);qm.push(jl+1);
						if(jl+1<m[j]){
							m[j]=jl+1;g[j]=1;
						}
						else{
							g[j]++;
						}
					}
				}
				for(int j=id-1;x[id]-x[j]<=d&&j>=1;j--){
					if(jl+1<=m[j]){
						qx.push(j);qm.push(jl+1);
						if(jl+1<m[j]){
							m[j]=jl+1;g[j]=1;
						}
						else{
							g[j]++;
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(g[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}