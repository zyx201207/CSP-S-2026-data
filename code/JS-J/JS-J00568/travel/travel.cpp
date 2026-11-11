#include<bits/stdc++.h>
using namespace std;
char c[5][10];
bool check1(){
    for(int i=0;i<=1;i++)
        if(c[1][i]!=c[3][i])
            return 0;
    return 1;
}
bool check2(){
    for(int i=0;i<=1;i++)
        if(c[2][i]!=c[4][i])
            return 0;
    return 1;
}
bool check3(){
    if(c[2][2]<='C'&&c[4][2]<='C')
        return 1;
    if(c[2][2]>='D'&&c[4][2]<='D')
        return 1;
    return 0;
}
bool check4(){
    if(c[2][2]<='C'&&c[4][2]<='C')
        if(abs(c[2][2]-c[4][2])==1)
            return 1;
    if(c[2][2]>='D'&&c[4][2]<='D')
        return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=4;i++)
        cin>>c[i];
    if(!check1())
        cout<<"0000";
    else if(!check2())
        cout<<"1000";
    else if(!check3())
        cout<<"1100";
    else if(!check4())
        cout<<"1110";
    else
        cout<<"1111";
    return 0;
}
