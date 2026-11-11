#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        string q1,q2;
        q1=s1[0]+s1[1];
        q2=s2[0]+s2[1];
        if(q1==q2){
            cout<<"1";
            bool j1=false,j2=false;
            if(s1[2]-'A'<3){
                j1=true;
            }
            else{
                j1=false;
            }
            if(s2[2]-'A'<3){
                j2=true;
            }
            else{
                j2=false;
            }
            //cout<<" "<<j1<<" "<<j2<<endl;
            if(j1==j2){
                cout<<"1";
                if(abs(s1[2]-s2[2])==1){
                    cout<<"1";
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
