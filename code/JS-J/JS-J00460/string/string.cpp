#include<bits/stdc++.h>
using namespace std;
long long n;
struct s{
    long long a;
    string si;
}st[200005];
string total;
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>st[i].a;
        cin>>st[i].si;
        for(long long j=1;j<=st[i].a;j++){
            total+=st[i].si;
        }
    }
    long long l=total.size(),ans=0;
    string rtotal;
    for(long long i=l-1;i>=0;i--){
        rtotal+=total[i];
    }
    for(long long i=0;i<l;i++){
        if(total[i]!=rtotal[i]) ans++;
    }
    ans/=2;
    cout<<ans;
    return 0;
}
