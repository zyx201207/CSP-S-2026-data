#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string re;
    bool f1=false,f2=false,f3=false;
    getline(cin,re);
    string a1=re.substr(0,2);
    string a2=re.substr(3,3);
    string b1=re.substr(7,2);
    string b2=re.substr(10,3);
    if(a1==b1){
        cout<<1;
        f1=true;
    }
    else cout<<0;
    if(f1&&(a2.substr(0,2)==b2.substr(0,2))){
        cout<<1;
        f2=true;
    }
    else cout<<0;
    char a=a2[2],b=b2[2];
    if((f1&&f2)&&((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F'))){
        cout<<1;
        f3=true;
    }
    else cout<<0;
    if((f1&&f2&&f3)&&(abs(int(a)-int(b))==1)){
        cout<<1;
    }
    else{
        if((f1&&f2&&f3)&&(abs(int(a)-int(b))==2)&&((a=='D'&&b=='F')||(a=='F'&&b=='D'))){
            cout<<1;
        }
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
