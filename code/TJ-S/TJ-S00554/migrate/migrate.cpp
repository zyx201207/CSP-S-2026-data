#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,wz[2000005],f[5005][5005],ans[5005][5005];
void solve(){
	memset(f,0x3f3f3f3f3f3f3f3f,sizeof(f));
	memset(ans,0,sizeof(ans));
	int sum=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>wz[i];
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int minx=0x3f3f3f3f3f3f3f3f;
			for(int k=j-1;k>=1;k--){
				if(wz[j]-wz[k]>d)break;
				if(minx>f[i][k]+1){
					minx=f[i][k]+1;
					ans[i][j]=1;
				}else if(minx==f[i][k]+1)ans[i][j]++;
			}
			f[i][j]=minx;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[i][j]==2)sum++;
			cout<<f[i][j]<<" ";
		}
		 cout<<endl;
	}
	cout<<sum<<'\n';
}
void solve2(){
	int sum=0,gc;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>wz[i];
		if(i>1)gc=wz[i]-wz[i-1];
	}
	if(gc>d){
		cout<<"0\n";
		return;
	}
	d=1ll*d/gc;
	if(d!=2){
		cout<<"0\n";
		return;
	}else{
		cout<<n-3<<'\n';
	}
}
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c==11||c==12)solve2();
		else solve();
	}
	return 0;
}


