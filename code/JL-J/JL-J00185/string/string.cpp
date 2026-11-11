#include<bits/stdc++.h>
using namespace std;
int l;
int main(){
    //freopen(string.in,"r",stdin);
    //freopen(string,"w",stdout);
    string h[1000];
    string hf[1000];
    string z[1000];
    int s[1000];

    cin>>l;
    for(int i=0;i<l;i++){
        cin>>z[i];
        cin>>s[i];
    }
    for(int i=0;i<l;i++){ //uchuzifuzhuanneiwupin
        for(int j=0;j<s[i];j++){
            h[i]=z[i];

        }
    }
    for(int i=l;i>0;i--){
        for(int j=l;j>s[i];j--){
            hf[i]=z[i];
            cout<<hf[i];
        }
    }









    return 0;
}
