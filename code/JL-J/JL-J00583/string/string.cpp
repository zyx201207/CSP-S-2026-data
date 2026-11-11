#include<bits/stdc++.h>
using namespace std;
long long n,a,o=0,p=0;
string b,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>b;
        for(long long j=0;j<a;j++){
            s+=b;
        }
    //cout<<12;
        o+=a;
    }
    for(long long i=0;i<=o/2;i++){
        if(s[i]!=s[o-i-1]){
            p++;
        }
    }
    cout<<p;
    return 0;
}
