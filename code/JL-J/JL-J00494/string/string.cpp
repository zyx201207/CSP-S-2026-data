#include<bits/stdc++.h>
using namespace std;
string s;
huiwen(string n){
    string x=n;
    long long a;
    f=0;
    for(int i=1;i<=n.size();i++){
        x-='0';
        a+=10*x%10;
        x=x/10;
        f++;
    }
    if(a==n-'0'){
        return 1;
    }
    return f;
    return 0;
}
int main(){
freopen("string.in","w"stdin);
freopen("string.out","w"stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>s;
if(huiwen(s)==1){
    cout<<'0';
}else{
    cout<<huiwen(s);
}
return 0;
}

