#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005],b[200005],tot;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		int cnt=0;
		tot=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1){
				b[++tot]=a[j];
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=tot;j++)a[j]=b[j];
			n=tot;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
