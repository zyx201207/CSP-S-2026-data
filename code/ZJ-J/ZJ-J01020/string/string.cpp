#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000+5;
int a[N],ans;
char str[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>str[i];
    }
    int l=1,r=n;
    while(l<r){
        int p=min(a[l],a[r]);
        a[l]-=p,a[r]-=p;
        if(str[l]!=str[r]){
            ans+=p;
        }
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    cout<<ans;
}
//finish at 9:10