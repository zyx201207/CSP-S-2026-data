#include<bits/stdc++.h>
using namespace std;
long long n,s[20000005],ans;
string c[20000005],sum2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i]>>c[i];
    sum2=c[1];
    for(int i=1;i<=n;i++) if(c[i]!=sum2) sum2=c[i];
    if(sum2==c[1]){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++) ans+=s[i];
    cout<<ans/2;
    return 0;
}
