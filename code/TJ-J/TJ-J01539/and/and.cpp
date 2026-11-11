#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		for(int j=i+1;j<=n-m+1;j++){
			int h=a[i];
			for(int k=j;k<j+m&&k<=n;k++){
				h&=a[k];
			}
			ans=max(ans,h);
		}
	}
	cout<<ans;
	return 0;
}
