#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[M],c[N],d[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			c[++cnt]=a[j];
			if(b[a[j]]==2){
				b[a[j]]=1;
				for(int k=d[a[j]]+1;k<cnt;k++){
					b[c[k]]=0;
				}
				cnt=d[a[j]];
			}
			d[a[j]]=cnt;
		}
		for(int j=1;j<=cnt;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
