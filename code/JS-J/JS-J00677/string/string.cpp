#include<bits/stdc++.h>
using namespace std;

long long n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long a;
    string c;
    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    long long len=s.size();
    long long t=len/2;
    while(t>0){
        if(s[t-1]!=s[len-t]){
            ans++;
        }
        t--;
    }
    cout<<ans;
    return 0;
}
