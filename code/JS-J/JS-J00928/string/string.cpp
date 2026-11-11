#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,ans=0;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        long long a;
        string b;
        cin>>a>>b;
        cnt+=a;
        for(int i=0;i<a;i++){
            s+=b;
        }

    }

    for(long long i=0;i<cnt/2;i++){
        if(s[i]!=s[cnt-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
