#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=32;
int n,m,a[N],ans;
bool b[N][M],u[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		u[i]=1;
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)
		for(int j=1;j<=30;j++) b[i][j]=((a[i]>>j-1)&1);
	for(int i=30;i;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(b[j][i]&&u[j]) cnt++;
		if(cnt>=m){
			ans+=(1ll<<i-1);
			for(int j=1;j<=n;j++)
				if(u[j]&&!b[j][i]) u[j]=0;
		}
	}
	cout<<ans;
	return 0;
}