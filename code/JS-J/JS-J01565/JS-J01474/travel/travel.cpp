#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int x1,x2;
    x1=(c1[0]-'0')*10+(c1[1]-'0');
    x2=(c2[0]-'0')*10+(c2[1]-'0');
    //cout<<x1<<' '<<x2;
    if(x1!=x2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
    }
    int se1,se2;
    se1=(s1[0]-'0')*10+(s1[1]-'0');
    se2=(s2[0]-'0')*10+(s2[1]-'0');
    //cout<<se1<<' '<<se2;
    if(se1==se2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    char num1=s1[2];
    char num2=s2[2];
    if(num1=='A' || num1=='B' || num1=='C'){
        if(num2=='D' || num2== 'F'){
            cout<<"00";
            return 0;
        }
        else{
            cout<<1;
        }
    }
    if(num1=='D' || num1== 'F'){
        if(num2=='A' || num2=='B' || num2=='C'){
            cout<<"00";
            return 0;
        }
        else{
            cout<<1;
        }
    }
    if(num1=='A' && num2!='B'){
        cout<<0;
        return 0;
    }
    if((num1=='B' && num2 !='A') && num2!='C'){
        cout<<0;
        return 0;
    }
    if(num1=='C' && num2 !='B'){
        cout<<0;
        return 0;
    }
    if(num1=='D' && num2 !='F'){
        cout<<0;
        return 0;
    }
    if(num1=='F' && num2 !='D'){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}
