#include<bits/stdc++.h>
#define int long
using namespace std;
struct node{
    int a;
    string b;
};
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    node cs[n+10]={};
    for(signed i=0;i<n;i++){
        cin>>cs[i].a>>cs[i].b;
    }
    string s;
    for(signed i=0;i<n;i++){
        for(signed j=0;j<cs[i].a;j++){
            s.append(cs[i].b);
        }
    }
    int sum=0;
    for(signed i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            sum++;
        }
    }
    cout<<sum;
    //zhushi
    return 0;
}
