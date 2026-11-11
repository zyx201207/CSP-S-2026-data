#include<bits/stdc++.h>
using namespace std;
int main(){
    fre("travel.in","r",stdin);
    fre("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b,c;
    a='s1[2]'-'A'+1;
    b='s2[2]'-'A'+1;
    if(a>b){
        c=a-b;
    }
    else{
        c=b-a;
    }
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if((a+b==9)||(a+b<=5&&c!=3)){
                cout<<"1";
                if(c==1){
                    cout<<"1";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
