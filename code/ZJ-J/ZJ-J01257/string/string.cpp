#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	int r=n;
	for(int l=1;l<r;l++){
		while(l<r&&a[l]){
			int now=min(a[l],a[r]);
			if(c[r]==c[l]){
				a[l]-=now;
				a[r]-=now;
			}else{
				ans+=now;
				a[l]-=now;
				a[r]-=now;
			}
			if(a[r]==0)r--;
		}
	}
	cout<<ans;
	return 0;
}
