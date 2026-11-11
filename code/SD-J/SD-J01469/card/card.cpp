#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500005;
int n,m,a[N],ans[N],qzn[N];
bool f[N];
	signed main()
{
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
		for(int j=1;j<=m;j++){
			qzn[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(qzn[a[j]]){
				for(int k=qzn[a[j]];k<j;k++){
					f[k]=0;
					qzn[a[k]]=0;
				}
			}
			qzn[a[j]]=j;
			f[j]=1;
		}
		for(int j=1;j<=n;j++){
			if(f[j]){
				ans[a[j]]++;
			}
			f[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
