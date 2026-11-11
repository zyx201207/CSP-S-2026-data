#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,l=0,cnt=0;
    string s;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;++i){
        long long a;
        char c;
        cin>>a>>c;
        l+=a;
        for(long long j=l;j<l+a;++j){
            s+=c;
        }
    }
    for(long long i=0;i<l/2;++i){
        if(s[i]!=s[l-i-1]){
            cnt++;

        }
    }
    cout<<cnt;

    return 0;
}
