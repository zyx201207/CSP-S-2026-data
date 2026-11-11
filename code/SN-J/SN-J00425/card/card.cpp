#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[512345];
int ans[312345];

		int cnt[512345];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		int ck=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=ck;k++){
				if(cnt[k]==a[j]){
					ck=max(i-1,1ll);
					break;
				}
			}
			ck++;
			cnt[ck]=a[j];
		}
		for(int j=1;j<=ck;j++){
			ans[cnt[j]]++;
		}
		for(int j=1;j<=ck;j++){
			cout<<cnt[j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}	
