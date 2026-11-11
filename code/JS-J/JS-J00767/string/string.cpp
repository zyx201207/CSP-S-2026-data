#include <bits/stdc++.h>
using namespace std;
string s="";
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long ai;
        string ci;
        cin>>ai>>ci;
        for(long long j=1;j<=ai;j++){
            s=s+ci;
        }
    }
    long long cnt=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
