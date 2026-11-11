#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s="";
    cin>>n;
    while(n--){
        int m;
        char c;
        cin>>m>>c;
        while(m--) s+=c;
    }
    int ans=0,l=s.size();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
