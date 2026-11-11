#include <bits/stdc++.h>
using namespace std;

char ce(string a,string b){
    if(a[2]=='C'){
        if(b[2]=='A') return '1';
        if(b[2]=='B') return '1';
    }
    else if(a[2]=='A'){
        if(b[2]=='C') return '1';
        if(b[2]=='B') return '1';
    }
    else if(a[2]=='B'){
        if(b[2]=='A') return '1';
        if(b[2]=='C') return '1';
    }
    if(a[2]=='D'){
        if(b[2]=='F') return '1';
    }
    else if(a[2]=='F'){
        if(b[2]=='D') return '1';
    }
    return '0';
}
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    string c1,c2,s1,s2,ans;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) ans+='1';
    else ans+='0';
    if(s1[0]==s2[0]&&s1[1]==s2[1]) ans+='1';
    else ans+='0';
    ans+=ce(s1,s2);
    if(ce(s1,s2)=='1'&&abs(s2[2]-s1[2])==1) ans+='1';
    else ans+='0';
    cout<<ans;
    return 0;
}
