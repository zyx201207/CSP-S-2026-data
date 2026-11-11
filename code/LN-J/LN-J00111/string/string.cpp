#include <bits/stdc++.h>
using namespace std;
struct num{
    long long a;
    char c;
}cnt[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s=" ";
    long long ans=0,cct=0;
    for(int i=1;i<=n;i++){
        cin>>cnt[i].a>>cnt[i].c;
        cct+=cnt[i].a;
        for(int j=1;j<=cnt[i].a;j++){
            s+=cnt[i].c;
        }
    }
    for(int i=1;i<=cct/2;i++){
        if(s[i]!=s[cct-i+1]){
            cout<<s[i]<<s[cct-i+1]<<endl;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
