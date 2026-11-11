#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ull=unsigned long long;
using i128=__int128;
using Pii=pair<int,int>;
const int maxN=2e5+10;
LL n,m;
LL a[maxN];
int cnt0[35];
bool vis[maxN][32];
bitset<32> ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<32;j++)
			cnt0[j]+=(a[i]>>j)&1;
	}
//for(int i=0;i<=30;i++) cout<<cnt0[i]<<' ';
//cout<<'\n';
	for(int i=30;i>=0;i--){
		if(cnt0[i]>=m){
			ans[i]=1;
//cout<<i<<'\n';
			for(int j=0;j<=30;j++)
				for(int k=1;k<=n;k++)
					if((a[k]&(1<<j))&&((a[k]&(1<<i))==0)&&!vis[k][j]){
//cout<<k<<'-'<<j<<"----\n";
						cnt0[j]--;
						vis[k][j]=1;
					}
		}
	}
	cout<<ans.to_ullong();
	return 0;
}
/*
5 3
31 3 1 15 7
*/
