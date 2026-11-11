#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long b;
    cin>>b;
    long long a;
    char q;
    string m,n;
    long long p=0;
    for(long long i=1;i<=b;i++){
        cin>>a>>q;
        for(long long j=1;j<=a;j++){
            m[p]=q;
            p++;
        }
    }
    for(long long i=0;i<p;i++){
        n[i]=m[p-i-1];
    }
    long long cnt=0;
    for(long long i=0;i<p;i++){
        if(n[i]!=m[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
