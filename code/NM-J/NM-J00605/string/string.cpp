#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,c[N],ans;
char a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i]>>a[i];
    for(int i=1,j=n;i<j;){
        if(a[i]!=a[j]) ans+=min(c[i],c[j]);
        if(c[i]>c[j]) c[i]-=c[j],--j;
        else if(c[i]<c[j]) c[j]-=c[i],++i;
        else --j,++i;
    }
    cout<<ans;
    return 0;
}
