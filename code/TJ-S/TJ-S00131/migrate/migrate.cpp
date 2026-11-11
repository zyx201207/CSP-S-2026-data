#include<bits/stdc++.h> 
using namespace std;
int c,t,ans=1;
void f(q){
	for(int i=1;i<n;i++){
		int m=1;
		for(inr j=i+1;j<=n;j++){
			if(x[q][j]-x[q][i]<0){
				m+=(x[q][j]/x[q][i]);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n[t+2],d[t+2],x[t+2][100000];
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[i][j];
		}
		cout<<ans<<endl;
	}
}
