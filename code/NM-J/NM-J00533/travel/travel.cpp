#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<"1";
        if(int(c[0]*10+c[1])==int(d[0]*10+d[1])){
            cout<<"1";
            if((char(c[2])<='C'&&char(d[2])<='C')||(char(c[2])>='D'&&char(d[2])>='D')){
               cout<<"1";
               if(char(c[2])+1==char(d[2])||char(c[2])==char(d[2])+1){
                cout<<"1";
               }
               else if(char(c[2])=='D'&&char(d[2])=='F'||char(c[2])=='F'&&char(d[2])=='D'){
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}
