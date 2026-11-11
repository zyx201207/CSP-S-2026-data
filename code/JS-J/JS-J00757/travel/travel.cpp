#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c1,c2;
int a,b;
char R1,R2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>a>>R1>>c2>>b>>R2;
    if(c1!=c2){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(a!=b)cout<<"000";
        else{
            cout<<"1";
            if(R1>'C'){
                if(R2<='C') cout<<"00";
                else{
                    cout<<"1";
                    if(abs(R1-R2)!=1) cout<<"0";
                    else cout<<"1";
                }
            }
            else{
                if(R2>'C') cout<<"00";
                else{
                    cout<<"1";
                    if(abs(R1-R2)!=1) cout<<"0";
                    else cout<<"1";
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
