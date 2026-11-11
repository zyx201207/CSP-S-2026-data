#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,len,mid,ans,sa,sb,ia,ib,a[N],b[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char op;
        cin>>a[i]>>op;
        b[i]=op-'a';
        len+=a[i];
    }
    mid=(len+1)/2,ia=1,ib=n;sa=0,sb=0;
    while(sa<=mid&&sb<=mid){
        int ret=0,f=1;
        if(b[ia]==b[ib])f=0;
        if(a[ia]>a[ib]){
            sa+=a[ib];sb+=a[ib];
            a[ia]-=a[ib];
            ret+=a[ib];
            ib--;
        }
        else if(a[ia]<a[ib]){
            sa+=a[ia];sb+=a[ia];
            a[ib]-=a[ia];
            ret+=a[ia];
            ia++;
        }
        else{
            sa+=a[ia];sb+=a[ib];
            ret+=a[ia];
            ia++;ib--;
        }
        ans+=ret*f;
    }
    cout<<ans;
    return 0;
}
