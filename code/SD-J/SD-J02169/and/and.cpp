#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
long long b[32],zs=0,l,r,ans,yq,gs;
bool w[N][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		w[i][31]=1;
	}
	b[0]=1;
	sort(a+1,a+1+n);
	while(zs<31){
		zs++;
		b[zs]=b[zs-1]*2;
	}
	yq=31;
	while(zs>=0){
		gs=0;
		for(int i=n;i>=1;i--){
			if(w[i][yq]&&(a[i]&b[zs])){
				gs++;
				w[i][zs]=1;
			}else continue;
			if(gs>=m)break;
		}
		if(gs>=m){
			yq=zs;
			ans+=b[zs];
		}
		zs--;
	} 
	cout<<ans;
	return 0;
}
