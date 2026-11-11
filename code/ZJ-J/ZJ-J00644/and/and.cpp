#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool b[2000005][35];
bool vis[200005],will[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxbit=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int j=a[i],k=1;
		while(j){
			b[i][k]=(j&1);
			j>>=1;
			k++;
			if(j!=0) maxbit=max(maxbit,k);
		}
	}
	for(int bit=maxbit;bit>=1;bit--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			will[i]=!b[i][bit];
			cnt+=b[i][bit];
		}
		if(cnt>=m){
			ans=ans+(1LL<<(bit-1));
			for(int i=1;i<=n;i++) vis[i]|=will[i];
		}
	}
	cout<<ans;

	return 0;
}
