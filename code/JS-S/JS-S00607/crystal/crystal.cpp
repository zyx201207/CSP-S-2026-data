#include<bits/stdc++.h>
#define int long long
using namespace std;
void fre(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
int n,m,a[500005],x=0,v,ans=0;
signed main(){
    fre();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==a[2]){
        cout<<m;
        return 0;
    }
    else{
        x=a[2]-a[1];
        while(m>=0){

            ans++;
            v++;
            m-=v*x;
        }
    cout<<ans<<endl;
    return 0;
    }
}
