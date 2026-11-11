#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int p1=s1[0]*10+s1[1];
    int p2=s2[0]*10+s2[1];
    char z1=s1[2];
    char z2=s2[2];
    int zuowei1,zuowei2;
    if(z1=='A'||z1=='B'||z1=='C') zuowei1=0;
    else zuowei1=1;
    if(z2=='A'||z2=='B'||z2=='C') zuowei2=0;
    else zuowei2=1;
    if(c1==c2) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(p1==p2) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(zuowei1==zuowei2) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(abs(z1-z2)==1) cout<<"1";
    else{
        cout<<"0";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
