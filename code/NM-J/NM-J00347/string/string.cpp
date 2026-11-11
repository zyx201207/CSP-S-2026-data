#include <bits/stdc++.h>
using namespace std;
bool uio(string s){
    long long j=s.size();
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}
long long ufo(string s){
    long long j=s.size(),cnt=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[j]){
            cnt++;
        }
        j--;
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s;
    cin>>n;
    for(long long i=0;i<n;i++){
        long long a;
        char b;
        cin>>a>>b;
        for(long long j=0;j<a;j++){
            s+=b;
        }
    }
    if(uio(s)){
        cout<<"0";
        return 0;
    }
    cout<<ufo(s);
    return 0;
}
