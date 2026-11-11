//骊宫高处入青云，仙乐风飘处处闻。 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt,ans;
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	for(long long base=30;base>=0;base--){
		cnt=0;
		for(long long i=1;i<=n;i++){
			if(vis[i]&&((a[i]>>base)&1)==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(long long i=1;i<=n;i++){
				if(((a[i]>>base)&1)==0){
					vis[i]=0;
				}
			}
			ans+=(1<<base);
		}
	}
	cout<<ans;
	return 0;
}
