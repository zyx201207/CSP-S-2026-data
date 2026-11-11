#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    int a1,b1;
    cin>>a1>>a;
    cin>>b1>>b;
    if(a>b){
        swap(a1,b1);
        swap(a,b);
    }
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    else{
        if(a[0]==b[0] && a[1]==b[1]){
            if((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D')){
                if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='C')||(a[2]=='D'&&b[2]=='F')){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                    return 0;
                }
            }
            else{
                cout<<"1100";
                return 0;
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    return 0;
}
