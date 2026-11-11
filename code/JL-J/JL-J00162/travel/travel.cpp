#include<bits/stdc++.h>
using namespace std;
int zhuan(char c){
    if(c=='A')return 1;
    else if(c=='B')return 2;
    else if(c=='C')return 3;
    else if(c=='D')return 14;
    else if(c=='F')return 15;
}
int tongce(int a,int b){
    if(a+b==29)return 1;
    else if(a+b<=5)return 1;
    else return 0;
}
int lin(int a,int b){
    if(a-b==1||b-a==1)return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    char a1=c2[2],b1=c4[2];
    int aa=zhuan(a1),bb=zhuan(b1);
    if(c1==c3){//che
        cout<<"1";
        if(c2[0]==c4[0]&&c2[1]==c4[1]){//pai
                cout<<"1";
                if(tongce(aa,bb)==1){//tongce
                    cout<<"1";
                    if(lin(aa,bb)==1)
                        cout<<"1";
                    else cout<<"0";
                }
                else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
