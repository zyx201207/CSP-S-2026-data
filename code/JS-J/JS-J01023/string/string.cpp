#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,a[N];
long long ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1,j=n;i<=j;){
        int t=min(a[i],a[j]);
        if(c[i]^c[j]) ans+=t;
        a[i]-=t,a[j]-=t;
        if(a[i]==a[j]) i++,j--;
        else if(a[i]) j--;
        else i++;
    }
    cout<<ans;
}
/*

//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout); <- again

Can anybody see me?

luogu uid=978088

*/
