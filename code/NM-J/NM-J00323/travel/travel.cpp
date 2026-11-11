#include<bits/stdc++.h>
using namespace std;
int c1,c2,tc,tp,tb,a,b,l;
string z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>z1>>c2>>z2;
    if(c1==c2){
        tc=1;

        if(z1[0]==z2[0] && z1[1]==z2[1]){
            tp=1;

            if(z1[2]=='A' || z1[2]=='B' || z1[2]=='C'){
                a=1;
            }
            else{
                a=0;
            }
            if(z2[2]=='A' || z2[2]=='B' || z2[2]=='C'){
                b=1;
            }
            else{
                b=0;
            }
            if(a==1 && b==1){
                tb=1;
                if(z1[2]=='A' && z2[2]=='B' || z1[2]=='C' && z2[2]=='B'){
                    l=1;
                }
                else{
                    l=0;
                }
            }
            else{
                if(a==0 && b==0){
                    tb=1;
                    l=1;
                    cout<<tc<<tp<<tb<<l;
                }
                else{
                    tb=0;
                }
            }
        }
        else{
            tp=0;

        }
    }
    else{
        tc=0;
        tp=0;
        tb=0;
        l=0;
    }



    cout<<tc<<tp<<tb<<l;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
