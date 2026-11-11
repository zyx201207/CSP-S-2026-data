#include<bits/stdc++.h>
using namespace std;
int n,a;
string s,s_in;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>s_in;
        for(int j=1;j<=a;j++){
            s+=s_in;
        }
    }
    int ans=s.size()/2;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]==s[s.size()-i-1])ans--;
    }
    cout<<ans;
    return 0;
}
