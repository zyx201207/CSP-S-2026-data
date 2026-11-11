#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        string y;
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            s+=y;
        }
    }
    long long ans=0;
    for(iny i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i])ans++;
    }
    cout<<ans;
    return 0;
}
