#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
string s;
int n,a[N],f[N],nw[N],v[N][35],m,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int cnt=1,x=a[i];
		while(x>0){
			v[i][cnt++]=x%2;
			x/=2;
		}
	}
	int lst=1;
	for(int j=30;j>=1;--j){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(nw[i]==1&&lst==0&&f[i]==1){
				f[i]=0;
				nw[i]=0;
			}
			if(v[i][j]==1&&f[i]==0){
				++cnt;
			}else{
				nw[i]=1;
				++f[i];
			}
		}
		if(cnt>=m){
			ans+=1<<(j-1);
			lst=1;
		}else{
			lst=0;
		}
	}
	cout<<ans;
	return 0;
}
