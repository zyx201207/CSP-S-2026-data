#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    int c1,c2;
    bool o=false;
    string s1,s2,a,b;
    cin>>c1>>s1>>c2>>s2;
    a=s1[0]+s1[1];
    b=s2[0]+s2[1];
    int c=int(s1[2]);
    int d=int(s2[2]);
    if(c1==c2){
        o=true;
        if(a==b){

            if(c>=65&&d<=67){
                if(c==d-1&&c+d!=135||d==c-1&&c+d!=135){
                    cout<<1111;


                }else{
                    cout<<1110;
                }
            }else if(c+d==138){
                cout<<1111;
        }else{
            cout<<1100;
        }


    }else{
        cout<<1000;
        }

    }
    if(o==false){
        cout<<0000;
    }





    return 0;
}
