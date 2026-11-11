#include<bits/stdc++.h>
using namespace std;
long long n,a,q=0,ans=0;
string s="";
char ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>ch;
        q+=a;
        for(long long i=1;i<=a;i++)s+=ch;
    }
    for(long long i=0;i<=q/2;i++){
        if(s[i]!=s[q-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
