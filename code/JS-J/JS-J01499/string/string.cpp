#include<bits/stdc++.h>
using namespace std;
string s;
int n,a;
int l=1,r,ans;
string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        r+=a;
        while(a--){
            s+=c;
        }
    }
    s=" "+s;
    while(l<r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
