#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>ca>>sa>>cb>>sb;
    int x=(ca[0]-'0')*10+ca[1]-'0';
    int y=(cb[0]-'0')*10+cb[1]-'0';
    if(x==y){
        cout<<"1";
        if(sa[0]==sb[0]&&sa[1]==sb[1]){
            cout<<"1";
            char cx=sa[2];
            char cy=sb[2];
            if((cx>='A'&&cx<='C'&&cy>='A'&&cy<='C')||(cx>='D'&&cx<='F'&&cy>='D'&&cy<='F')){
                cout<<"1";
                x=cx-'A',y=cy-'A';
                if(abs(x-y)==1){
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
