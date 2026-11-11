#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N],p[35],vis[N],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	p[0]=1;
	for(int i=1;i<=31;i++)p[i]=p[i-1]*2;
	for(int i=31;i>=0;i--){
		int d=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0){
				if((a[j]&p[i])!=0){
					d++;
				}
			}
		}
		if(d>=m){
			for(int j=1;j<=n;j++){
				if(vis[j]==0&&(a[j]&p[i])==0){
					vis[j]=1;
				}
			}
			ans+=p[i];
		}
	}
	cout<<ans;
	return 0;
}
