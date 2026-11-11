#include<bits/stdc++.h>
using namespace std;
#define N 2000005

int c,t,n;
long long d;
long long x[N]; 

int ans=0;

bool cmp(int u,int v){
	if(x[v]-x[v-2]>d)return cmp(u,v-1);
	else return x[u+3]-x[u]>d&&x[u+2]-x[u]<=d&&x[u+3]-x[u+1]<=d;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i;j<=n-2;j++){
				if(cmp(i,j))ans++;
			}
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
