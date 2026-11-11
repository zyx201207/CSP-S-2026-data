#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >>n;
    long long ans=0;
    string ss="";
    for(int i=1;i<=n;i++){
        int a;char s;
        cin >>a >>s;
        while(a--){
            ss+=s;
        }
    }
    string js=ss.substr(0,ss.size()/2);
    reverse(js.begin(),js.end());
    string bs=ss.substr(0,(ss.size()+1)/2);
    bs+=js;
    for(int i=1;i<=ss.size();i++){
        if(ss[i-1]!=bs[i-1]){
            ans++;
        }
    }
    cout <<ans;

return 0;
}
