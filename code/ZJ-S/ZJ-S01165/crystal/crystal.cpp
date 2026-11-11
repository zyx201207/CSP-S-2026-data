
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	const int MAXN=500010;
	int n,m;
    int val,ans=0;
    int a[MAXN];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		val=0;
		for(int j=1;j<i;j++){
			val+=a[i]-a[i-j];
			if(val<=m&&j+1>ans){
				ans=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}