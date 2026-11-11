#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define pb push_back
const int N=5e5+100;
int n,m;
int a[N];
int mp[N];
int ans[N];
inline void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(mp,0,sizeof mp);
		int cnt=0;
		for(int j=1;j<i;j++){
			
			
			for(int k=cnt;k>=1;k--){
				if(k==a[j]){
					for(int p=k;p>=1;p--){
						mp[p]=mp[cnt--];
					}
					cnt-=(j-k);
					break;
				}
			}
			
			mp[++cnt]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int k=cnt;k>=1;k--){
				if(k==a[j]){
					for(int p=k;p>=1;p--){
						mp[p]=mp[cnt--];
					}
//					cnt-=(j-k);
					break;
				}
			}
			mp[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			ans[mp[j]]++;
		}
	}
	for(int x=1;x<=m;x++) cout<<ans[x]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	//cin>>_;
	while(_--) Solve();
	return 0;
}

