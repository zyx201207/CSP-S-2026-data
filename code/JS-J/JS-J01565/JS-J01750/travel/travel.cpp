#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,a2;
char b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    for(long long i=0;i<s1.length();i++){
        if(int(s1[i])<65){
            a1+=s1[i];
        }
        else b1=s1[i];
    }
    for(long long i=0;i<s2.length();i++){
        if(int(s2[i])<65){
            a2+=s2[i];
        }
        else b2=s2[i];
    }
    if(a1!=a2){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    if(int(b1)<=67&&int(b2)<=67||int(b1)>67&&int(b2)>67){
        cout<<'1';
        if((int(b1)-int(b2))==1||(int(b1)-int(b2))==-1){
            cout<<'1';
            return 0;
        }
        cout<<'0';
    }
    else cout<<"00";
    return 0;
}
