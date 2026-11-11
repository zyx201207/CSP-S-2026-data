#include <bits/stdc++.h>
#define int long long
#define N 2000005
#define MN 805
using namespace std;
int c,T,n,d,pos[N],dis[MN][MN],tim[MN][MN];
void sv_1(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
			for(int j=1;j<=n;j++){
				dis[i][j]=0x3f3f3f3f;
				tim[i][j]=0;
			}
			dis[i][i]=0;
		}
		
		for(int l=2;l<=n;l++){
			for(int i=1;i+l-1<=n;l++){
				int j=i+l-1;
				for(int k=i+1;k<j;k++){
					
				}
			}
		}
	}
}
void sv_2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
			cin>>pos[i];
	}
	int mx=0,mi=n;
	for(int i=1;i<=n;i++){
		if(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=n){
			mx=max(mx,i);
			mi=min(mi,i);
		}
	}
	int ans=0,ll=1;
	if(mx-mi>2){
		cout<<0;
		return;
	}
	for(int i=1;i<mi;i++){
		while(ll<n&&pos[ll+1]-pos[i]<=n)ll++;
		if(ll-mi>2)break;
		else{
			ans+=n-ll;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>c>>T;
	if(c<=6){
		sv_1();
	}else if(c==13||c==14){
		sv_2();
	}
	return 0;
}