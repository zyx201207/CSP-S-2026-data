#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
string s;
int main(){
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=0;i<n;i++){
        int m;
        char e;
        cin>>m;
        cin>>e;
        for(int j=0;j<m;j++){
            s=s+e;
        }
    }for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            s[i]=s[s.size()-i-1];
            ans++;
        }
    }cout<<ans;
    return 0;
}
