#include <bits/stdc++.h>
using namespace std;
string s;
long long ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long u;
        char v;
        cin>>u>>v;
        for(long long j=1;j<=u;j++){
                s+=char(v);
        }
    }
    long long l=0;
    long long r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
