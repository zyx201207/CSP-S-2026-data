#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n,m,ans;
bitset<N>b[32];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		for(int j=0;x;++j){
			b[j][i]=x&1;x>>=1;
		}
	}for(int i=30;i>=0;--i){
		if(b[i].count()<m)continue;
		ans+=1<<i;
		for(int j=1;j<=n;++j)
			if(!b[i][j])
				for(int k=0;k<i;++k)
					b[k][j]=0;
		
	}cout<<ans;
	return 0;
}
