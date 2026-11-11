#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long l=0;
    cin>>n;
    string c;
    string s=" ";
    for(long long i=1;i<=n;i++){
        long long a;
        cin>>a;
        cin>>c;
        l+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long ans=0;
    for(long long i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1])
        ans++;
    }
    cout<<ans;
    return 0;
}
