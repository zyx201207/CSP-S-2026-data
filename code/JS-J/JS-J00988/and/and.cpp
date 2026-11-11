#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],ans=0;
void dfs(long long s,long long f,long long l){
    if(s==m){
        ans=max(f,ans);
        return;
    }
    for(int i=l+1;i<=n-m+s+1;i++){
        dfs(s+1,f&a[i],i);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
    for(int i=1;i<=n-m;i++){
        dfs(1,a[i],i);
    }
    cout<<ans;
    return 0;
}
