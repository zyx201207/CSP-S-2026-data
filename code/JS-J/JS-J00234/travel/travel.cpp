#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2; 
bool one(){
    if(c1 == c2)return true;
    return false;
}
bool two(){
    if(s1[0]==s2[0] && s1[1] == s2[1])return true;
    return false;
}
bool three(){
    if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C')return true;
    if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')return true;
    return false;
}
bool four(){
    if((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))return false;
    if(abs(s1[2] - s2[2]) == 1)return true;
    if(s1[2] == 'D' && s2[2] == 'F')return true;
    if(s1[2] == 'F' && s2[2] == 'D')return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(one())cout<<1;
    else cout<<0;

    if(one() && two())cout<<1;
    else cout<<0;

    if(one() && two() && three())cout<<1;
    else cout<<0;

    if(one() && two() && three() && four())cout<<1;
    else cout<<0;
    return 0;
}
