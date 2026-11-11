#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int x;char c;cin>>x>>c;
        for(int j=1;j<=x;j++)s+=c;
    }
    string t=s;
    reverse(t.begin(),t.end());
    cout<<'\n'<<t<<'\n'<<s;
    if(t==s){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<s.size();i++)if(s[i]!=t[i])cnt++;
    cout<<cnt/2;
    return 0;
}
