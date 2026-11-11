#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,p,cnt;
signed main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		cnt=a[k];
		bool vis[N]={0};
		for(int i=1;i<m;i++){
			for(int j=1;j<=n;j++){
				if(j!=k&&(cnt&a[j]>cnt)&&!vis[j]){
					cnt&=a[j],p=j;
					break;
				}
			}
			vis[p]=1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
