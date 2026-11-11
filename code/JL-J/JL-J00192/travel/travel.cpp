#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("travel.txt","r",stdin);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
    }else{
        cout<<"0000";return 0;
    }
    bool a=s1.substr(0,s1.size()-1)==s2.substr(0,s2.size()-1);
    if(a){
        cout<<'1';
    }else{
        cout<<"000";return 0;
    }
    char p=s1[s1.size()-1],q=s2[s1.size()-1];
    if((p>='A' && p<='C' && q>='A' && q<='C') or (p>='D' && p<='F' && q>='D' && q<='F')){
        cout<<'1';
        cout<<(max(p-q,q-p)==1);
    }else{
        cout<<"00";
    }
    return 0;
}
