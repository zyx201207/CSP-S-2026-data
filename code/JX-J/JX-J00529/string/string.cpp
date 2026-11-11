#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char c;
    string s;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a>0){
            s+=c;
            a--;
        }
    }
    int ans=0;
    int x=s.size()-1;
    int i=0;
    while(x>=s.size()/2&&i<s.size()/2){
        if(s[i]!=s[x]){
            ans++;
        }
        x--;
        i++;
    }
    cout<<ans;
    return 0;
}
