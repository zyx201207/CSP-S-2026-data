#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,lena,ans=0;
LL a[N];
string c[N];
string x="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) x+=c[i];
        lena+=a[i];
    }
    for(int i=0;i<lena/2;i++){
        if(x[i]!=x[lena-1-i]) ans++;
    }
    cout<<ans;
    return 0;
}
