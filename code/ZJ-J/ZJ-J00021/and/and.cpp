#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],c[200005],book[200005],lg[35],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	lg[0]=1;
	for(int i=1;i<=30;i++){
		lg[i]=lg[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		book[i]=1;
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(book[j]&&a[j]/lg[i]==1){
				++cnt;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(book[j]&&a[j]/lg[i]==0){
					book[j]=0;
				}
			}
			ans+=lg[i];
		}
		for(int j=1;j<=n;j++){
			a[j]%=lg[i];
		}
	}
	cout<<ans;
	return 0;
}
