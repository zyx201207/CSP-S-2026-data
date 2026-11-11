#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1e2;
int a[N][35],p[N][35];
int n,m,ans[35],anss;
void work(int x,int y){
	int cnt=0;
	while(x){
		cnt++;
		if(x&1==1) a[y][cnt]=1;
		x/=2;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	cout<<sizeof(a)/1024/1024<<"\n";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		work(q,i);
	}
	int lev=0,cnt2=n;
	for(int i=30;i>=1;i--){
		int fans=0;
		lev++;
		for(int j=1;j<=cnt2;j++)
			if(a[j][i]==1) fans++;
		if(fans>=m){
			cnt2=0;
			for(int j=1;j<=n;j++)
			if(a[j][i]==1){
				++cnt2;
				for(int k=1;k<=30;k++) p[cnt2][k]=a[j][k];
			}
			memset(a,0,sizeof(a));
			for(int j=1;j<=cnt2;j++){
				for(int k=1;k<=30;k++)
					a[j][k]=p[j][k];
			}
			ans[i]=1;
		}
	}
	int _power=1;
	for(int i=1;i<=30;i++){
		anss+=ans[i]*_power;
		_power*=2;
	}
	cout<<anss;
}