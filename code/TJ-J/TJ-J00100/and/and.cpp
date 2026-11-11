#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int k=0;
		int cnt=a[i];
		for(int j=i+1;j<=n;j++){
			cnt&=a[j];
			k++;
			if(k==m)break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
