#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],pos[N],ans[N];
int q[N],r;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		memset(pos,0,sizeof(pos));
		r=0;
		for(int j=i;j<=n;j++){
			if(pos[a[j]]>0){
				for(int k=pos[a[j]]+1;k<=r;k++) pos[q[k]]=0;
				r=pos[a[j]];
				continue;
			}
			r++;
			q[r]=a[j];
			pos[a[j]]=r;
		}
		for(int j=1;j<=m;j++)
		   if(pos[j]>0) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

