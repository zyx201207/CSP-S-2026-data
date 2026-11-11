#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }for(int i=1;i<=n;i++){
        int x;char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++)s+=c;
    }for(int i=0;i<(s.size()+1)/2;i++){
        if(s[i]!=s[s.size()-1-i])ans++;
    }cout<<ans;
    return 0;
}
