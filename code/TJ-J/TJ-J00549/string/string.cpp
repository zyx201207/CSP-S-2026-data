#include<bits/stdc++.h>
using namespace std;
long long a,l,cnt,ans,n;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
        l+=a;
    }
    cnt=l-1;
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[cnt-i]) ans++;
    }
    cout<<ans;
    return 0;
}
