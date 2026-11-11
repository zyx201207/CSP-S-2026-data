#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;

    if(c1!=c2){
        cout<<"0000"<<"\n";
        return 0;
    }else{
        cout<<"1";
    }

    int r1,r2;
    r1=(s1[0]-'0')*10+s1[1]-'0';
    r2=(s2[0]-'0')*10+s2[1]-'0';
    if(r1!=r2){
        cout<<"000"<<"\n";
        return 0;
    }else{
        cout<<"1";
    }

    if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')){
        cout<<"1";
    }else{
        cout<<"00"<<"\n";
        return 0;
    }

    if(abs(s1[2]-s2[2])==1)
        cout<<"1"<<"\n";
    else
        cout<<"0"<<"\n";

    return 0;
}
