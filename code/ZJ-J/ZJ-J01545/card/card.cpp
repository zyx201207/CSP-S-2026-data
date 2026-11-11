#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,a[500010],lst[300010],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool FLAG=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];if(a[i]<a[i-1]) FLAG=0;
	} 
    if(FLAG){
    	for(int i=n;i>=1;i--){
    		if(!ans[a[i]]) ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
    for(int i=n;i>=1;i--){
    	if(!lst[a[i]]) lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=lst[a[j]];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
