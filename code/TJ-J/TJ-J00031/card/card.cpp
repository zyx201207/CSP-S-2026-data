#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],b[300005];
int ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
	else{
		int x=n;
		while(x--){
			memset(b,0,sizeof(b));
			for(int i=n-x+1;i<=n;i++){
				if(b[a[i]]!=0){
					memset(b,0,sizeof(b));
				}
				b[a[i]]=i;
			}
			for(int i=1;i<=m;i++){
				if(b[i]!=0){
					ans[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
