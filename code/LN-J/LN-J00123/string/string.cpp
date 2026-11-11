#include <bits/stdc++.h>
using namespace std;
int m[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s,b;
    long long c=0;
    for(int i=0;i<n;i++){
        long long n;
        cin>>n;
        m[i]=n;
        string a;
        cin>>a;
        b+=a;
    }
    for(int i=0;i<n/2;i++){
        long long mx=max(m[i],m[n-i-1]),mn=min(m[i],m[n-i-1]);
        if(b[i]==b[n-1-i]&&m[i]!=m[n-i-1]){
            c+=(mx-mn);
            if(m[n]==mx)m[n+1]+=(mx-mn);
            else m[n-i-2]+=(mx-mn);
        }
        if(b[i]!=b[n-i-1]){
            c+=mx;
        }
    }
    cout<<c;
    return 0;
}
