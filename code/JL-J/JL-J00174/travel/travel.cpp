#include<iostream>
using namespace std;
bool leftright(char c){
    if(c=='F' || c=='D'){
        return 1;
    }
    else return 0;
}//left=1 right=0
int main(){
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
    // freopen mustn't '//' !
    int c1,c2;
    char st1,st2;
    int p1,p2;
    cin>>c1;
    cin>>p1>>st1;
    cin>>c2;
    cin>>p2>>st2;
    if(c1 == c2) cout<<1;
    else cout<<0;
    if((c1 == c2) && (p1 == p2)) cout<<1;
    else cout<<0;
    if(((c1 == c2) && (p1 == p2)) && (leftright(st1)==leftright(st2))) cout<<1;
    else cout<<0;

    if((((c1 == c2) && (p1 == p2)) && (leftright(st1)==leftright(st2))) && (char(st1-1)==st2 || char(st1+1)==st2)) cout<<1;
    else cout<<0;
    return 0;
}
