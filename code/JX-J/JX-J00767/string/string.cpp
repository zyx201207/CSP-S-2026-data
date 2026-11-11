#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n ==1)cout<<"0";
    if(n==2){
        int d,f;
        char k,l;
        cin>>d>>k>>f>>l;
        if(d==f)cout<<d;
        else{
            if(d>f){
                cout<<f;
            }
            if(d<f){
                cout<<d;
            }
        }
    }
    return 0;
}

