#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<1;
        if(c2[1]==c4[1]&&c2[2]==c4[2]){
            cout<<1;
            if(c2[3]=='D'&&c4[3]=='F'||(c4[3]=='D'&&c2[3]=='F')){
                cout<<1<<1;
                
            }else if(c2[3]+1==c4[3]||c2[3]-1==c4[3]&&(c2[3]!='C'&&c4[3]!='D')||(c4[3]!='C'&&c2[3]!='D')){
                cout<<1<<1;
            }
        }else{
            cout<<0<<0;
        }

        
    } 
    else cout<<0;
    
    return 0;
}
