#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,tot=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        tot+=a;
        for(long long i=0;i<a;i++){
            s+=c;
        }
    }
    for(long long i=0;i<tot/2;i++){
        if(s[i]!=s[tot-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}