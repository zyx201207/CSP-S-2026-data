#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,ans=0;
    cin>>n;
    string s;
    for(long long i=0;i<n;i++){
        int m;
        string a;
        cin>>m>>a;
        for(long long j=0;j<m;j++){
            s+=a;
        }
    }
    long long l=0,r=s.size()-1;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
            continue;
        }
        l++;
        r--;
        ans++;
    }
    cout<<ans;
    return 0;
}
