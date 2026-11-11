#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+7;
int n,m;
int a[N];
int b[N];
int pre[N];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=abs(pre[i-1]+a[i]);
    }
    for(int i=1;i<=n;i++){
        if((a[i]*i-pre[i])==m){
            ans=i;
        }
    }
    cout<<ans;
	return 0;
}
