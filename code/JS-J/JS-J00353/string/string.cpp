#include<bits/stdc++.h>
using namespace std;
string s;
long long l=0,n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        while(a--){
            l++;
            s[l]=b;
        }
    }
    for(long long i=0;i<l/2;i++){
        if(s[i+1]!=s[l-i]) ans++;
    }
    cout<<ans;
    return 0;
}
