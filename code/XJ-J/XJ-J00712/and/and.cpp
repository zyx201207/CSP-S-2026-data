#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans,maxn=INT_MIN;
int main(){
	cin>>n>>m;
	freopen("stding.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
	}
	if(m==1){
		ans=maxn;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}