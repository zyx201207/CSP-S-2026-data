#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
int vis[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int flag=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
//			cout<<((a[j]>>i)&1)<<" ";
			if(((a[j]>>i)&1)==1&&!vis[j]){
				cnt++;
			}
			else if(flag){
				vis[j]=1;
			}
		}
//		cout<<"\n";
//		cout<<i<<" "<<cnt<<"\n";
		if(cnt>=m){
			ans+=(1<<i);
			flag=1;
			for(int j=1;j<=n;j++){
//			cout<<((a[j]>>i)&1)<<" ";
				if(((a[j]>>i)&1)==1&&!vis[j]){}
				else{
					vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
