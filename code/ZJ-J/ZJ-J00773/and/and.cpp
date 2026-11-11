#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
int n,m;
int a[200005],cnt=0;
int tmp[200005],vis[200005];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		for(int i=1;i<=n;i++)tmp[i]=0;
		cnt=0;
		for(int j=1;j<=n;j++){
			int now=((a[j]>>i)&1);
//			cout<<now<<" ";
			if(now&&vis[j]==0){
				cnt++;
				tmp[j]=1;
			}
		}
//		cout<<"\n";
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(tmp[i]==0){
					vis[i]=1;
				}
				
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
//		cout<<i<<" ";
		
		if(ans==0)ans=a[i];
		else ans=(ans&a[i]);
	}
	cout<<ans;
}
I_don_t_want_to_AFO{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
