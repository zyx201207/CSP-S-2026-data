#include<bits/stdc++.h>
using namespace std;
long long n,a[500050],m,ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l = 1,r = 2;
    while(r<=n&&l<r){
        if(1ll*(a[r]-a[r-1])*(r-l)<=m){
            m-=1ll*(a[r]-a[r-1])*(r-l);
            r++;
        }
        else{
            ans = max(ans,r-l);
            m+=a[r-1]-a[l];
            l++;
        }
    }

    cout<<ans;
	return 0;
}
