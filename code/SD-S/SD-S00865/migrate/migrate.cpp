#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N],lx[N],zx[N];
int n;long long d;
void fly(int x,long long jl){
	if(jl>zx[x]||(lx[x]>2&&jl==zx[x])) return;
	if(jl==zx[x])lx[x]++;
	if(jl<zx[x]){
		zx[x]=jl;
		lx[x]=1;
	}for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d) fly(i,jl+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		memset(zx,0x3f,sizeof zx);
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long cnt=0;
		for(int i=1;i<n;i++){
			fly(i,0LL);
			for(int j=i+1;j<=n;j++){
				if(lx[j]==2) cnt++;
				lx[j]=0;zx[j]=INT_MAX;
			}
		}cout<<cnt<<"\n";
	}
	return 0;
}
