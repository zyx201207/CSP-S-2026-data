#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,m,num,ans=(1<<30)-1;
int a[N],vis[N],b[N][35],sum[35];
vector<int> res;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	num=n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		int t=a[i],cnt=0;
		while(t) {
			b[i][cnt++]=t%2;
			t/=2;
		}
		for(int j=cnt; j<=31; j++) b[i][j]=0;
	}
	for(int j=31; j>=0; j--) {
		for(int i=1; i<=n; i++) {
			sum[j]+=b[i][j];
		}
	}
	int f=0;
	for(int j=31; j>=0; j--) {
		if(sum[j]>=m) {
			for(int i=1; i<=n; i++) {
				if(b[i][j]==0) {
					if(num>m&&vis[i]==0) {
						vis[i]=1;
						num--;
					}
					if(num==m) {
						f=1;
						break;
					}
				}
			}
		}
		if(f==1) break;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i]==0) res.push_back(a[i]);
	}
	for(int i=0; i<m; i++) ans=(ans&res[i]);
	cout<<ans;
	return 0;
}