#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,shu,jg=0;
    string s,hw,zf,zhw;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>shu>>zf;
        for(int j=1;j<=shu;j++){
            s+=zf;

        }
    }
    long long sh;
    if(s.size()%2==1){
        sh=s.size()/2+1;
    }
    else{
        sh=s.size()/2;
    }
    for(int i=0;i<sh;i++){
        zhw+=s[i];
    }
    for(int i=s.size()/2-1;i>=0;i--){
        zhw+=s[i];
    }
    for(int i=s.size()-1;i>=0;i--){
        hw+=s[i];
    }
    for(int i=0;i<=s.size()-1;i++){
        if(zhw[i]!=hw[i]){
            jg++;
        }
    }
    cout<<jg;
}
