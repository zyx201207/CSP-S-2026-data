#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int s[N],c[M];
int ans[M];
int tt;
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	memset(c,-1,sizeof c);
	for(int i=0;i<n;i++){
		int nc;
		cin >> nc;
		if(c[nc]!=-1){
			while(s[--tt]!=nc)
				ans[s[tt]]+=i-c[tt],c[tt]=-1;
			ans[s[tt]]+=i-c[tt],c[tt]=-1;
		}
		else
			s[tt++]=nc,c[nc]=i;
	}
	for(int i=1;i<=m;i++){
		if(c[tt]==-1)
			cout << ans[i] << " ";
		else
			cout << ans[i]+(n-c[i]) << " ";
	}
	//I have a good idea but I'm TLE and MLE so I can't write there;
}
