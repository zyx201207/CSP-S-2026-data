#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<"1";
    else{
       cout<<"0000";
       return 0;
    }
    string l1,l2;
    char n1,n2;
    n1=s1[2];
    n2=s2[2];
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((n1=='F'&&n2!='D')||(n1=='D'&&n2!='F')||(n2=='F'&&n1!='D')||(n2=='D'&&n1!='F')){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(abs(int(n1)-int(n2))==1)cout<<"1";
    else cout<<"0";
    return 0;
}
