#include<bits/stdc++.h>
using namespace std;
bool sameside(char a,char b){
    int aa=(a=='A'||a=='B'||a=='C');
    int bb=(b=='A'||b=='B'||b=='C');
    return aa==bb;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
    string x1="";x1=x1+s1[0]+s1[1];char y1=s1[2];
    string x2="";x2=x2+s2[0]+s2[1];char y2=s2[2];
    if(y1=='F') y1--;
    if(y2=='F') y2--;
    cout<<(c1==c2);
    cout<<((c1==c2)&&(x1==x2));
    cout<<((c1==c2)&&(x1==x2)&&sameside(y1,y2));
    cout<<((c1==c2)&&(x1==x2)&&sameside(y1,y2)&&(abs(y1-y2)==1));
    return 0;
}
