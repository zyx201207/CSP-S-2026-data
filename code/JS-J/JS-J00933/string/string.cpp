#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long i=1;i<=a;i++){
            s+=c;
        }
    }
    long long ans=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
