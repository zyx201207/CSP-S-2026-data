#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=0,cnt=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        l+=x;
        while(x--){
            s+=c;
        }
    }
    for(int i=0;i<=l/2-1;i++){
        if(s[i]!=s[l-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
