#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cf;
    string sf;
    string cs;
    string ss;
    cin>>cf>>sf>>cs>>ss;
    int numf=0;
    int nums=0;
    for (int i=0;i<2;i++){
        if (i==0){
            numf+=sf[i]*10;
            nums+=ss[i]*10;
        }else{
            numf+=sf[i];
            nums+=ss[i];
        }
    }
    if (cf==cs){
        cout<<"1";
        if(numf==nums){
          cout<<"1";
          int a=sf[2]-48-16;
          int b=ss[2]-48-16;
          if (a<=3&&b<=3){
            cout<<"1";
            if (a-b==1||b-a==1){
                cout<<"1";
            }else{
                cout<<"0";
            }
          }else if(a>3&&b>3){
            cout<<"1";
            if (a-b==1||b-a==1){
                cout<<"1";
            }else{
                cout<<"0";
            }
          }else{
            cout<<"0";
            cout<<"0";
          }

      }else{
        cout<<"0";
        cout<<"0";
        cout<<"0";
      }
    }else{
        cout<<"0";
        cout<<"0";
        cout<<"0";
        cout<<"0";
    }


    return 0;
}
