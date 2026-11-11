#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int x1,y1,x2,y2,i=0;
    for(char p:s1){
        i++;
        if(i==1){
            x1=10*(p-'0');
        }
        else if(i==2){
            x1=x1+(p-'0');
        }
        else{
            y1=p-'A'+1;
        }
    }
    i=0;
    for(char p:s2){
        i++;
        if(i==1){
            x2=10*(p-'0');
        }
        else if(i==2){
            x2=x2+(p-'0');
        }
        else{
            y2=p-'A'+1;
        }
    }
    if(c1!=c2) cout<<"0000";
    else {
        cout<<"1";
        if(x1!=x2) cout<<"000";
        else{
            cout<<"1";
            if((y1<=3 and y2>3) or (y1>3 and y2<=3)) cout<<"00";
            else{
                cout<<"1";
                if(abs(y1-y2)!=1) cout<<"0";
                else cout<<"1";
            }
        }
    }
    return 0;
}
