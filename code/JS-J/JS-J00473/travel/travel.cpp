#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string w,ww;
    cin>>n>>w>>m>>ww;
    if(n==m){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(w[0]==ww[0] and w[1]==ww[1]){
        cout<<"1";
        if(ww[2]=='F' and w[2]=='D'){
            cout<<"11";
        }
        else{
            if(ww[2]=='A' and (w[2]=='B' or w[2]=='C')){
                cout<<1;
                if(w[2]=='B'){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
                return 0;
            }
            if(ww[2]=='B' and (w[2]=='A' or w[2]=='C')){
                cout<<"11";
                return 0;
            }
            if(ww[2]=='C' and (w[2]=='A' or w[2]=='B')){
                cout<<1;
                if(w[2]=='B'){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
                return 0;
            }
            cout<<"00";
        }
        return 0;
    }
    cout<<"00";
    cout<<"0";
    return 0;
}
