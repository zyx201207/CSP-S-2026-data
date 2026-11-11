#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
   if(c1[1]==c2[1]||c1[2]==c2[2]){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1[1]==s2[1]||s1[2]==s2[2]){
        cout<<1;
        if(s1[3]=="A"&&s1[3]=="B"&&s1[3]=="C"){
            if(s2[3]=="A"&&s2[3]=="B"&&s2[3]=="C"){
                cout<<1;
        }else{
            cout<<0;
            cout<<0;
            return 0;
        }
        }
        if(s1[3]=="D"&&s1[3]=="E"){
            if(s2[3]=="D"&&s2[3]=="E"){
                cout<<1;
            }else{
                cout<<0;
                cout<<0;
                return 0;
            }
        }
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1[3]=="A"||s2[3]=="B"){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
     if(s1[3]=="B"||s2[3]=="A"&&s2[3]=="C"){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
     if(s1[3]=="C"||s2[3]=="B"){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
     if(s1[3]=="D"||s2[3]=="E"){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
     if(s1[3]=="E"||s2[3]=="D"){
        cout<<1;
    }else{
        cout<<0;
        return 0;
    }
    return 0;
}
