#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,c2,s1,s2,s11,s21,s12,s22;
    cin>>c1,c2;
    putchar(s1);
    putchar(s11);
    putchar(s12);
    putchar(s2);
    putchar(s21);
    putchar(s22);
    if(c1=c2){cout<<1;
        if(s1==s2&&s11==s21){cout<<1;
            if(s12=='A','B','C'&&s22=='A','B','C'||s12=='D','E'&&s22=='D','E'){cout<<1;
                if(s12=='A'&&s22=='B'||s12=='B',s22=='A','C'||s12=='C'&&s22=='B'||s12=='D'&&s22=='E'||s12=='E'&&s22=='D'){cout<<1;}
                else{cout<<0;}
            }
            else{cout<<00;}
        }
        else{cout<<000;}
    }
    else{cout<<0000;}
    return 0;
}
