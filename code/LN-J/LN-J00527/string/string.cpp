#include<bits/stdc++.h>
using namespace std;
string s;
int n,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        char op;
        cin>>t>>op;
        for(int j=1;j<=t;j++) s+=op;
    }
    for(int i=0;i<(s.size()/2);i++){
        if(s[i]!=s[s.size()-1-i]) c++;
    }
    cout<<c;
    return 0;
}
