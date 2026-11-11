#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,ans=0;
    cin>>n;
    string s;
    while(n--){
        long long a;
        cin>>a;
        char c;
        cin>>c;
        for(long long i=0;i<a;i++){
            s[i+cnt]=c;
        }
        cnt+=a;
    }
    for(long long i=0;i<cnt/2;i++){
        if(s[i]!=s[cnt-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
