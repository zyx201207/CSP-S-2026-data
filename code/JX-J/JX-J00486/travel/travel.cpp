#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int num1 = (s1[0]-'0')*10 + (s1[1] - '0');
    int num2 = (s2[0]-'0')*10 + (s2[1] - '0');
    char d1 = s1[2],d2 = s2[2];
    int g1 ,g2;

    if(c1 == c2)cout<<1;
    else {cout<<"0000";return 0;}
    if(num1 == num2)cout<<1;
    else {cout<<"000";return 0;}
    if(d1 == 'A' ||d1 == 'C' ||d1 == 'B')  g1 = 2;
    else g1 = 1;

    if(d2 == 'A' ||d2 == 'C' ||d2 == 'B')  g2 = 2;
    else g2 = 1;

    if(g2 == g1) cout<<1;
    else {cout<<"00";return 0;}

    if(d1 + 1 == d2 || d1 - 1 == d2) cout<<1;
    else cout<<0;

    return 0;
}
