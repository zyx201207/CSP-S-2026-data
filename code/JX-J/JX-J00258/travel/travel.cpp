#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
int aa,bb,cc,dd,nb,nd;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    aa=(a[0]-48)*10+(a[1]-48);
    cc=(c[0]-48)*10+(c[1]-48);
    bb=(b[0]-48)*10+(b[1]-48);
    dd=(d[0]-48)*10+(d[1]-48);
   nb=(int)b[2];
    nd=(int)d[2];
    if(aa!=cc){
        cout<<"0000";
        return 0;
    }
    else{
        if(bb!=dd){
            cout<<"1000";
            return 0;
        }else{
        if(nb<=67&&nd>67||nb>67&&nd<=67){
            cout<<"1100";
            return 0;
        }
        else{
        if(nb<=67&&nd<=67){
            if(nb>nd){
                if(nb-nd==1){
                    cout<<"1111";
                    return 0;
                }
            else{
                cout<<"1110";
                return 0;
                }
        }else{
            if(nd-nb==1){
                cout<<"1111";
                return 0;
            }
            else{
                cout<<"1110";
                return 0;
            }
        }
            }
        else{
            cout<<"1111";
            return 0;
                }

        }
        }
    }
    return 0;
}
