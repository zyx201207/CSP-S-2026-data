#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s="";
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        while(x--){
            s+=c;
        }
    }
    for(int i=0;i<=(s.size()/2-1);i++){
        if(s[i]!=s[s.size()-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
