#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2, a3,a4;
    cin >> a1 >> a2 >>a3 >>a4 ;
    if( a1 != a3 ){
        cout<<"0000";
    }else{
        if( a2[0] == a4[0] &&a2[1] == a4[1]){
            if( ((a2[2] == 'D' && a4[2] == 'F')&&(a4[2] == 'D' && a2[2] == 'F')) ||((a4[2] == 'A'||a4[2] == 'B'||a4[2] == 'C') && (a2[2] == 'A'||a2[2] == 'B'||a2[2] == 'C'))){
                if( a2[2] == 'A' && a4[2] == 'C' ){
                    cout<<1110;
                }else if( a4[2] == 'A' && a2[2] == 'C' ){
                    cout<<1110;
                }else if( a2[2] == 'D' && a4[2] != 'F' ){
                    cout<<1110;
                }else if( a4[2] == 'D' && a4[2] != 'C' ){
                    cout<<1110;
                }else{
                    cout<<1111;
                }
            }else{
                cout<<1100;
            }
        }else{
            cout<<1000;
        }
    }
}
