#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c , cc;
    string s , ss;
    cin>>c>>s>>cc>>ss;
    bool no = 0;
    bool pai = 0;
    bool wei = 0;
    if(c==cc){
        cout<<"1";
        no = 1;
    }else{
        cout<<"0";
    }
    if(no && s[0]==ss[0] && s[1]==ss[1]){
        cout<<"1";
        pai = 1;
    }else{
        cout<<"0";
    }
    if(pai){
        if((s[2] >= 'A' && s[2] <= 'C' && ss[2] >= 'A' && ss[2] <= 'C') || (s[2] >= 'D' && s[2] <= 'F' && ss[2] >= 'D' && ss[2] <= 'F')){
            cout<<"1";
            wei = 1;
        }else{
            cout<<"0";
        }
    }else{
        cout<<"0";
    }
    if(wei && (s[2]+1 == ss[2]||s[2]-1==ss[2])){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
