#include<bits/stdc++.h>
using namespace std;
int main(){
    char a2[3],b2[3];
    int flag=4,a1,b1;
    freopen("travel.in","r",stdin);
    cin>>a1>>a2>>b1>>b2;
    char m=a2[2],n=b2[2];
    if(a1!=b1 ||a1==16||a1==1||b1==16||b1==1) flag=0;
    else if((a2[0]!=b2[0]) || (a2[1]!=b2[1])) flag=1;
    else if(!((m=='A'||m=='B'||m=='C') && (n=='A'||n=='B'||n=='C') || (m=='D'||m=='F') && (n=='D'||n=='F'))) flag=2;
    else if(!((m-'A')-(n-'A')==1 || (m-'A')-(n-'A')==-1)) flag=3;
    freopen("travel.out","w",stdout);
    for(int i=1;i<=4;i++){
        if(i<=flag) cout<<1;
        else cout<<0;
    }
    return 0;
}
