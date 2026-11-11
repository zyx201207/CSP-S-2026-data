#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=1e18+7;
int c,t,n,d,a[N],f[N],ans,e[N];
void stt(int s){
	for(int i=s;i<=n;i++)e[i]=0;
	for(int i=s;i<=n;i++){
		for(int j=s;j<i;j++){
			if(abs(a[i]-a[j])<=d){
				if(f[i]>f[j]+1){
					f[i]=f[j]+1;
					e[i]=1;
				}else if(f[i]==f[j]+1){
					f[i]=f[j]+1;
					e[i]++;
				}
			}
		}
	}for(int i=s;i<=n;i++){
//		cout<<e[i]<<" ";
		if(e[i]==2)ans++;
	}
//	cout<<"\n";
	return ;
}
void start(){
	ans=0;
	cin>>n>>d;
	for(int i=0;i<=n;i++){f[i]=INF;}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		f[i]=0;
		stt(i);
		f[i]=INF;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		start();
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



*/
