//zuoxianke 西安铁一中学 SN-J00679
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500001];
int ans[300001];
int x[500001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=r;k++){
				if(x[k]==a[j]){
					r=k-1;
					break;
				}
			}
			x[++r]=a[j];
		}
		for(int i=1;i<=r;i++){
			ans[x[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
