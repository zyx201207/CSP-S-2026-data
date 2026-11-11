#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
string s;
string s2;
long long g=0,ans=0;
void f(){
    for(int i=0;i<s.size()/2;i++){
        if(s2[i]!=s[i]) ans++;
        //cout<<s[i]<<' '<<s2[i];
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long sh;
        char z;
        cin>>sh>>z;
        while(sh--){
            s+=z;
        }
    }

    long long q=s.size()/2;
    for(int i=s.size()-1;i>=q;i--){
            s2[g++]=s[i];
            //cout<<s2[g-1];
    }
    //cout<<s2;
    f();

    cout<<ans;


return 0;
}

