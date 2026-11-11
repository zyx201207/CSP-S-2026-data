#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<'\n';
        return 0;
    }
    cout<<"1";
    string t1=s1.substr(0,2),t2=s2.substr(0,2);
    if(t1!=t2){
        cout<<"000"<<endl;
        return 0;
    }else cout<<"1";
    int f=0;
    if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
        cout<<"1";
        f=1;
    }else if(s1[2]=='D' || s1[2]=='F' && s2[2]=='D' || s2[2]=='F'){
        cout<<"1";
        f=2;
    }else{
        cout<<"00"<<endl;
        return 0;
    }
    int num=abs(s1[2]-s2[2]);
    if(num>2) cout<<"0"<<endl;
    if(f==1 && num==1) cout<<"1"<<endl;
    else if(f==num) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
