#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long add=1,sum=0;
        for(int j=i-1;j>=1;j--){
            if(sum+a[i]-a[j]<=m){
            	add++;
            	sum+=a[i]-a[j];
			}
            else break;
        }
        ans=max(ans,add);
    }
    cout<<ans;
    return 0;
}