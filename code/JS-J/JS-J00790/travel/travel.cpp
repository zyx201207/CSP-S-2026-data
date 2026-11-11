#include <iostream>

using namespace std;

string c1 , s1 , c2 , s2;

int n1,n2;

int main(){
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){

        cout<<1;

        if(s1.substr(0,2)==s2.substr(0,2)){

            cout<<1;

            if(s1[2]=='A')n1=1;
            else if(s1[2]=='B')n1=2;
            else if(s1[2]=='C')n1=3;
            else if(s1[2]=='D')n1=4;
            else if(s1[2]=='F')n1=5;

            if(s2[2]=='A')n2=1;
            else if(s2[2]=='B')n2=2;
            else if(s2[2]=='C')n2=3;
            else if(s2[2]=='D')n2=4;
            else if(s2[2]=='F')n2=5;

            if((n1<4&&n2<4)||(n1>3&&n2>3)){

                cout<<1;


                if(n1+n2!=7&&(n1-n2==1||n2-n1==1)){

                    cout<<1;

                }
                else{

                    cout<<"0";

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
    return 0;
}
