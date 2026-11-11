#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ln,ans;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>c;
        for(int j=0;j<m;j++){
            s+=c;
        }
    }
    ln=s.size();
    for(int i=0;i<ln;i++){
        if(s[i]!=s[ln-i]){
            ans++;
        }
    }
    cout<<ans-1;
    return 0;
}
