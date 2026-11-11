#include<bits/stdc++.h>
using namespace std;
int main(){
    long long c2,s2,c1,s1;
    char sz2,sz;
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    cin>>c1>>s1>>sz>>c2>>s2>>sz2;
    if(c1==c2){
        cout<<1;
    }
    else
        cout<<0;
    if(s1==s2){
        cout<<1;
        if(sz=="A"){
        if(sz2=="B"){
            cout<<1;
        }
        if(sz2=="C"){
            cout<<1;
        }
    }
    else if(sz=="B"){
        if(sz2=="A"){
            cout<<1;
        }
        if(sz2=="C"){
            cout<<1;
        }
    }
    else if(sz=="C"){
        if(sz2=="B"){
            cout<<1;
        }
        if(sz2=="A"){
            cout<<1;
        }
    }
    else if(sz=="D"||sz2=="D")
        if(sz=="F"||sz2=="F")
            cout<<1;
    else
        cout<<0;
    }
    else
        cout<<"00";
    if(sz=="A"){
        if(sz2=="B"){
            cout<<1;
        }
    }
    else if(sz=="B"){
        if(sz2=="A"){
            cout<<1;
        }
        if(sz2=="C"){
            cout<<1;
        }
    }
    else if(sz=="C"){
        if(sz2=="B"){
            cout<<1;
        }
    }
    else if(sz=="D"||sz2=="D")
        if(sz=="F"||sz2=="F")
            cout<<1;
    else
        cout<<0;
    return 0;
}
