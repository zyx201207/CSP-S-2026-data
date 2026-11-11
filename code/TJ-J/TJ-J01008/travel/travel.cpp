#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    int c1,c2;
    int s1,s2;
    cin >>c1 >>s1 >>c2 >>s2;
    if(c1!=01&&c1!=16){
        cout << 1;
    }
    else{
        cout <<0;
    }

    if(s2-s1>1||s1-s2>1){
        cout <<0;
    }
    else{
        cout << 1;
    }

    if(c2!=01&&c2!=16){
        cout << 1;
    }
    else{
        cout <<0;
    }

    if(s2-s1>1||s1-s2>1){
        cout <<0;
    }
    else{
        cout << 1;
    }

    return 0;
}
