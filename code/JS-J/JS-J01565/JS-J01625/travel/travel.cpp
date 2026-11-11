#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    int q=b[2]-'A';
    int w=d[2]-'A';
    int e=q,r=w;
    if(q<=2) q=0;
    else q=1;
    if(w<=2) w=0;
    else w=1;
    if(a==c){
        if(b[0]==d[0] && b[1]==d[1]){
            if((w==0 && q==0) || (w==1 && q==1)){
                if(w==1 && q==1){
                    cout<<"1111";
                    return 0;
                }
                if(e==r-1 || e==r+1){
                    cout<<"1111";
                    return 0;
                }
                cout<<"1110";
                return 0;
            }
            else{
                cout<<"1100";
            }

        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
