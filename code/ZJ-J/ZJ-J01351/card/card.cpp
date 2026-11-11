#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int n,m,a[N];
int tong[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	for(int l=1;l<=n;l++){
		long long ll=l;
		for(int r=l;r<l+n;r++){
			tong[a[r]]++;
			if(tong[a[r]]>=2){
				while(ll<r){
					tong[a[ll++]]--;
				}
			}
		}
		for(int j=0;j<=m;j++){
			if(tong[j]>0) ans[j]++;
		}
		for(int j=0;j<=m;j++) tong[j]=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}