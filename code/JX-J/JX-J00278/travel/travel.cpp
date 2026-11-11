#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int s1,s2;
char b1,b2;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>b1>>c2>>s2>>b2;
    if(c1==c2)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1==1 and s2==1)cout<<1;
    else if(s1==2 and s2==2)cout<<1;
    else if(s1==3 and s2==3)cout<<1;
    else if(s1==4 and s2==4)cout<<1;
    else if(s1==5 and s2==5)cout<<1;
    else if(s1==6 and s2==6)cout<<1;
    else if(s1==7 and s2==7)cout<<1;
    else if(s1==8 and s2==8)cout<<1;
    else if(s1==9 and s2==9)cout<<1;
    else if(s1==10 and s2==10)cout<<1;
    else if(s1==11 and s2==11)cout<<1;
    else if(s1==12 and s2==12)cout<<1;
    else if(s1==13 and s2==13)cout<<1;
    else if(s1==14 and s2==14)cout<<1;
    else if(s1==15 and s2==15)cout<<1;
    else if(s1==16 and s2==16)cout<<1;
    else if(s1==17 and s2==17)cout<<1;
    else if(s1==18 and s2==18)cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(((b1=='A' or b1=='B' or b1=='C') and (b2=='A' or b2=='B' or b2=='C')) or ((b1=='D' or b1=='F') and (b2=='D' or b2=='F')))cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if(b1=='A' and b2=='B')cout<<1;
    else if(b1=='B' and (b2=='A' or b2=='C'))cout<<1;
    else if(b1=='C' and b2=='B')cout<<1;
    else if(b1=='D' and b2=='F')cout<<1;
    else if(b1=='F' and b2=='D')cout<<1;
    else{
        cout<<0;
        return 0;
    }
    return 0;
}
