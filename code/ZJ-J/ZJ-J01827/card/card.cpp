#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],f[500005],pos[500005],ans[300005],b[500005];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			a[i]=b[i];
		}
		memset(f,0,sizeof f);
		memset(pos,0,sizeof pos);
		for(int i=l;i<=n;i++){
			if(f[a[i]]==0||pos[a[i]]==0){
				f[a[i]]=1;
				pos[a[i]]=i;
			}
			else if(f[a[i]]==1&&pos[a[i]]!=0){
				for(int j=pos[a[i]];j<i;j++){
					a[j]=0;
					pos[a[j]]=0;
				}
				pos[a[i]]=i;
			}
		}
		for(int i=l;i<=n;i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
