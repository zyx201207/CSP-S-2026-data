#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int ai;string c;
    for(int i=1;i<=n;i++){
        cin>>ai>>c;
        for(int j=1;j<=ai;j++){
            s=s+c;
        }
    }
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;r--;
    }
    cout<<ans;
    return 0;
}
