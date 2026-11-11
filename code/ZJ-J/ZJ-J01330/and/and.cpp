#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,e[200005][31],f[200005],ans;
int wop(int x){
	int k=1;
	for(int i=1;i<=x;i++) k*=2;
	return k;
}
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=30;j>=0;j--){
			e[i][j]=a%2;
			a/=2;
		}
	}
	for(int i=0;i<=30;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(e[j][i]==1) cnt++;
		}
		if(cnt<m) continue;
		else ans+=wop(30-i);
	}
	cout<<ans<<"\n";
	
	return 0;
}
