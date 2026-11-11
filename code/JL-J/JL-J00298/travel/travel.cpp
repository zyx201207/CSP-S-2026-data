#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    string n1,n2,a1,a2;
    cin>>n1>>n2>>a1>>a2;
    if(n1==a1)
        cout<<1;
    else
        cout<<0;
    if(n2[1]==a2[1] && n2[2]==a2[2])
        cout<<1;
    else
        cout<<0;
    if( ( (n2[3]=="A" || n2[3]=="B" || n2[3]=="C") && (a2[3]=="A" || a2[3]=="B" || a2[3]=="C") ) || ( (n2[3]=="D" || n2[3]=="E") && (a2[3]=="D" || a2[3]=="E") ) )
        cout<<1;
    else
        cout<<0;
    if( ( (n2[3]=="A" || n2[3]=="B" || n2[3]=="C") && (a2[3]=="A" || a2[3]=="B" || a2[3]=="C") ) || ( (n2[3]=="D" || n2[3]=="E") && (a2[3]=="D" || a2[3]=="E") ) ){
        if( (n2[3]=="A" && a2[3]=="B") || (n2[3]=="B" && a2[3]=="A") || (n2[3]=="B" && a2[3]=="C") || (n2[3]=="C" && a2[3]=="B") || (n2[3]=="D" && a2[3]=="E") || (n2[3]=="E" && a2[3]=="D"))
            cout<<1;
    }
    else
        cout<<0;
}
