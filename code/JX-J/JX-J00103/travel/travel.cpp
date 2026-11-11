#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",r,stdin);
    freopen("travel.out",r,stdout);
    string q,q1,a,a1;
    bool z=1;
    cin>>q>>q1>>a>>a1;
    for(int i=0;i<2;i++){
        if(q[i]!=a[i]){
            z=0;
        }
    }
    if(z==1){
        cout<<"1";
        for(int i=0;i<2;i++){
            if(q1[i]!=a1[i]){
                z=0;
            }
        }
        if(z==1){
            cout<<"1";
            char q2,a2;
            q2=q1[2];
            a2=a1[2];
            if((q2>='D' && a2<'D') || (a2>='D' && q2<'D'))z=0;
            if(z==1){
                cout<<"1";
                if(q2>='D'){
                    if(q2-2==a2 || q2+2==a2)cout<<"1";
                    else cout<<"0";
                }
                else{
                    if(q2-1==a2 || q2+1==a2)cout<<"1";
                    else cout<<"0";
                }
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
