#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=1;
    int b=1;
    int c=1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){cout<<"1";}else{cout<<"0";
        a=0;
    b=0;
    c=0;}

    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
                a=0;
                b=0;
                c=0;
        break;
        }
    }


    if(s1[2]=='A'){
        if(s2[2]=='F'||s2[2]=='D'){
            b=0;
        }
    }
    else if(s1[2]=='B'){
        if(s2[2]=='F'||s2[2]=='D'){
            b=0;
        }
    }
    else if(s1[2]=='C'){
        if(s2[2]=='D'||s2[2]=='F'){
            b=0;
        }

    }
    else if(s1[2]=='D'){
        if(s2[2]!='F'){
                b=0;
    }}
    else if(s1[2]=='F'){
            if(s2[2]!='D'){
                b=0;
            }
    }
    if(s1[2]=='A'){
        if(s2[2]!='B'){
c=0;
        }
    }
    else if(s1[2]=='B'){
        if(s2[2]!='A'||s2[2]!='B'){
            c=0;
        }
    }
    else if(s1[2]=='C'){
        if(s2[2]!='B'){
            c=0;
        }
    }
    else if(s1[2]=='D'){
        if(s2[2]!='F'){
            c=0;
        }
    }
    else if(s1[2]=='F'){
        if(s2[2]!='D'){
            c=0;
        }
    }
    cout<<a<<b<<c;


    return 0;

}
