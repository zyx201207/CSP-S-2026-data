#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    char m;
    long long n,a,b=0;
    long long i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        cin>>m;
        for(j=0;j<a;j++){
            s[b+j]=m;
        }
        b+=a;
    }
    long long ans=0;
    for(i=0;i<b/2;i++){
        if(s[i]!=s[b-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
